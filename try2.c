/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:53:00 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/10 12:48:42 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
# include <stdio.h> //needs to remove this
//# include "libft/libft.h"

//void read_line(char **)
int main(int argc, char *argv[])
{
	t_piece *final_pieces; //piecelist = final_pieces
    
	if (argc != 2)
    {
		ft_putstr("usage: ....\n"); // proper terms needs to be written, printf
        return (1);
    }
    
    final_pieces = parse_data(argv[1]); // parse_data = parser
    if (!final_pieces)
        return (NULL);
    


	//system("leaks a.out"); //needs to remove this
	return (1);
}

t_piece *parse_data(char *filename)
{
    char line_buff[545]; // line_buff = buf
    int fd;
    int buff_size; //bytecount = buff_size

    fd = open(filename, O_RDONLY);
    if (fd < 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	else
	{
        buff_size = read(fd, line_buff, 545);
        close (fd);
        if (buff_size < 19 || buff_size > 544)
            return (NULL);
        line_buff[buff_size] = '\0';
        if (!validator(line_buff, buff_size))
            return (NULL);
	}
    return (extract_line_buff(line_buff, buff_size)); //makelist = extract_line_buff
}

t_piece *extract_line_buff(char *line_buff, int buff_size)
{
    t_piece *current;
    t_piece *start; //beginning = start
    int i;
    char letter; // letter = pieceletter

    i = 0;
    letter = 'A';
    while (i < buff_size)
    {
        if (letter == 'A')
        {
            beginning = update_line_buff(line_buff + i, letter); //update_line_buff = makepiece
            current = beginning;
        }
        else

    }
}


t_piece *update_line_buff(char *line_buff, char letter)
{
    t_piece *piece
}