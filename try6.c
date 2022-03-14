#include <stdio.h>
#include <string.h>

int tetrimino_count(char *input)
{
    int i;
    int hashcount;

    i = 0;
    hashcount = 0;
    while (i <= 20)
    {
        if (input[i] && input[i]) != '.' && input[i] != '#' && input[i] != '\n')
            return (0);
        if ((i % 5) == 4)
        {
            if (input[i] != '\n')
                return (0);
        }
        if (input[i] == '#')
            hashcount++
        i++;
    }
    return (hashcount);
}

int next_to_counter(char *input)
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
        if (tetrimino_count(input[i]) != 4)
            return (0);
        if (next_to_counter(input[i]) != 6 && next_to_counter(input[i]) != 8)
            return (0);
        i += 21;
    }
    return (1);
}

typedef struct tetriminos_piece
{
    int cordinates[8];
    char letter;
    int x_point;
    int y_point;
    struct tetriminos_piece *next;

}   tet_item;

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


tet_item *parse_input(char *input, int size)
{
    tet_item 

    return (1);
}

int main(int argc, char *argv[])
{
    //char input[20] = "....\n...#\n...#\n..##\n";
    int fd;
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
    buff[size] = '\0';
    if (validate_tetriminos_shape(buff, size))
    {
        parse_input(buff, size);

    }
    return (1);
}