# include "fillit.h"

int main(int argc, char **argv)
{
    t_piece *piecelist;

}

typedef struct s_piece
{
    int blockcords[8];
    char pieceletter;
    int x_offset;
    int y_offset;
    struct s_piece *next;
}       t_piece;

if (argc != 2)
{
    ft_putstr("usage: ....\n");
    return (1);
}
if ((piecelist = parser(argv[1])) == NULL)
{
    ft_putstr("error\n");
    return(1);
}

parser

t_piece *parser(char *filename)
{
    char buf[545];
    int fd;
    int bytecount;

    fd = open(filename, O_RDONLY);
    bytecount = read(fd, buf, 545);
    close(fd);
    if (bytecount > 544 || bytecount < 19)
        return (NULL);
    buf[bytecount] = '\0';
    if (!valid(buf, bytecount))
        return (NULL);
        return (makelist(buf, bytecount)); 
}

int valid(char *buf, int size)
{
    int i;

    i = 0;
    while (i <= size)
    {
        if (charcount(buf + i) !=4)
            return (0);
        if (adjancecy_counter(buf + i) != 6 && adjancecy_counter(buf + i) != 8) //
            return (0);
        i +=21; //
    }
    return (1);
}

int charcount(char *buf)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (i < 19) //
    {
        if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
            return (0);
        if (buf[i] == '\n' && ) //
            return (0);
        if (buf[i] == '#')
            count++;
        i++;
    }
    if (!buf[i] || buf[i] != '\n')
        return (0);
    return (count);
}

int adjancecy_counter(char *buf)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < 19)//
    {
        if (buf[i] == '#')
        {
            if (i + 1 <= 18 && buf[i + 1] == '#')//
        ....}
    i++;
    }
    return (count);
}

makelist(buf, bytecount)
t_piece *makelist(char *buf, int size)
{
    t_piece *current;
    t_piece *beginning;
    int i;
    char pieceletter;

    i = 0;
    pieceletter = 'A';
    while (i < size)
    {
        if (pieceletter == 'A')
        {
            beginning = makepiece(buf + i, pieceletter);
            current = beginning;
        }
        else
        {
            current->next = makepiece(buf + i, pieceletter);
            current = current->next;
        }
        pieceletter++;
        i +=21;
    }
}

makepiece

t_piece *makepiece(char *buf, char pieceletter)
{
    t_piece *piece_ptr;
    int x;
    int y;
    int i;

    
}