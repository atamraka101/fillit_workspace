#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tetrimino_count(char *input)
{
    int i;
    int hashcount;

    i = 0;
    hashcount = 0;
    while (i < 20)
    {
        if (input[i] && input[i] != '.' && input[i] != '#' && input[i] != '\n')
            return (0);
        if (input[i] == '\n' && (i % 5) != 4)
                return (0);
        if ((i % 5) == 4 && input[i] != '\n')
                return (0);
        if (input[i] == '#')
            hashcount++;
        i++;
    }

    return (hashcount);
}

int count_adjacent_hashes(char *input)
{
    int i;
    int hashcount;

    i = 0;
    hashcount = 0;
    while (i < 19)
    {
        if (input[i] == '#')
        {
            if (i + 1 <= 18 && input[i + 1] == '#')
                hashcount++;
            if (i - 1 >= 0 && input[i - 1] == '#')
                hashcount++;
            if (i + 5 <= 18 && input[i + 5] == '#')
                hashcount++;
            if (i - 5 >= 0 && input[i - 5] == '#')
                hashcount++;
        }
        i++;
    }
    return (hashcount);
}

int validate_tetriminos_shape(char *input, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (tetrimino_count(&input[i]) != 4)
            return (0);
        if (count_adjacent_hashes(&input[i]) != 6 && count_adjacent_hashes(&input[i]) != 8)
            return (0);
        if (((i + 20) < (size - 1)) && input[i + 20] != '\n')
            return (0);
        i += 21;
    }
    return (1);
}

typedef struct tetriminos_piece
{
    int coordinates[8];
    char letter;
    int     x_offset;//column
    int     y_offset;//row
    struct tetriminos_piece *next;

}   tet_item;

int get_coordinates(char *input, int inSize, int *coords)
{
    int row;
    int column;
    int ndx;
    int i;

    row = 0;
    ndx = 0;
    i = 0;
    while (ndx < inSize && i < 8)
    {
        column = 0;
        while (column < 5)
        {
            if (input[ndx] == '#')
            {
                coords[i++] = row;
                coords[i++] = column;
            }
            column++;
            ndx++;
        }
        row++;
    }
    return (1);
}

int shift_coordinates_rc(int *coords, int r, int c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        coords[i] += r;
        coords[i + 1] += c;
        i += 2;
    }
    return (1);
}

int align_coordinates_top_left(int *coords)
{
    int r_offset;
    int c_offset;
    int i;

    r_offset = coords[0];
    c_offset = coords[1];
    i = 2;
    while (i < 8)
    {
        if (r_offset > coords [i])
            r_offset = coords[i];
        if (c_offset > coords[i + 1])
            c_offset = coords[i + 1];
        i += 2;
    }

    r_offset *= -1;
    c_offset *= -1;
    shift_coordinates_rc(coords, r_offset, c_offset);

    return (1);
}

void free_tet_list(tet_item *list)
{
    tet_item *temp;

    while(list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

tet_item *new_tet_item(char *input, int inSize, char letter)
{
    tet_item *newlist;

    newlist = (tet_item *)malloc(sizeof(tet_item));
    if (!newlist)
        return (NULL);
    get_coordinates(input, inSize, newlist->coordinates);
    //Align coordinates
    align_coordinates_top_left(newlist->coordinates);
    newlist->letter = letter;
    newlist->x_offset = 0;
    newlist->y_offset = 0;
    newlist->next = NULL;
    return (newlist);
}

tet_item *make_tet_list(char *input, int inSize)
{
    tet_item *current;
	tet_item *beginning;
	int		i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < inSize)
	{
		if (pieceletter == 'A')
		{
			beginning = new_tet_item(input + i, 20, pieceletter);
			current = beginning;
		}
		else
		{
			current->next = new_tet_item(input + i, 20, pieceletter);
			current = current->next;
		}
		pieceletter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

void display_tet_item(tet_item *tet_list)
{
    tet_item *current;
    int i;

    current = tet_list;
    while(current != NULL)
    {
        i = 0;
        printf("Tetriminos item:\n");
        printf("coordinates:");
        while (i < 8)
        {
            printf("%d ", current->coordinates[i]);
            i++;
        }
        printf("\n");
        printf("letter: %c\n", current->letter);
        printf("x_offset: %d, y_offset: %d\n", current->x_offset, current->y_offset);
        printf("\n");
        current = current->next;
    }
}
/*tet_item *parse_input(char *input, int size)
{
    //tet_item

    return (1);
}*/

int main(int argc, char *argv[])
{
    char input[42] = "....\n...#\n...#\n..##\n\n...#\n...#\n...#\n...#\n\0";
    int x = validate_tetriminos_shape(input, 42);
    printf("%d\n", x);

    printf("Checking coordinates\n");
    int cords[8];
    tet_item *list;

    list = make_tet_list(input, 42);
    display_tet_item(list);
    free_tet_list(list);
    /*tet_item *first;

    first = new_tet_item(&input[0], 20, 'A');
    int i;
    i = 0;

    printf("First item:\n");
    printf("coordinates:");
    while (i < 8)
    {
        printf("%d ", first->coordinates[i]);
        i++;
    }
    printf("\n");
    printf("letter: %c\n", first->letter);
    printf("x_offset: %d, y_offset: %d\n", first->x_offset, first->y_offset);

    free(first);
    */
    /*get_coordinates(&input[21], 20, cords);

    int i;

    i = 0;

    printf("Coordinates:");
    while (i < 8)
    {
        printf("%d ", cords[i]);
        i++;
    }
    printf("\n");
    align_coordinates_top_left(cords);

    printf("Shifted:");
    i = 0;
    while (i < 8)
    {
        printf("%d ", cords[i]);
        i++;
    }
    printf("\n");*/
    /*int fd;
    char  buff[545];
    int size;

    if (argc != 2)
    {
        //ft_putstr("usage: ./fillit input_file\n");
        printf("usage: ./fillit input_file\n");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        //ft_putstr("error\n");
        printf("error\n");
        return (1);
    }
    size = read(fd, buff, 545);
    close (fd);
    if (size < 19 || size >544)
        return (0);
    buff[size] = '\0';*/
    /*if (validate_tetriminos_shape(input, 20))
    {
        //parse_input(buff, size);

    }*/
    return (1);
}

