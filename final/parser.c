/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:34:26 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/16 15:11:55 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

tet_item *parser(char *filename)
{

	char	buff[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buff, 545);
	close(fd);
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	buff[bytecount] = '\0';
	if (!validate_tetriminos_shape(buff, bytecount))
		return (NULL);
	//return (make_tet_list(buff, bytecount));
	//free from main; free needed; if not use below 3 sentence not above one
	//tet_item *list;
	//list = make_tet_list(buff, bytecount);
	//free_tet_list(list);
}
