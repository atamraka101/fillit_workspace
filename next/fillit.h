/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:34:52 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/16 09:38:56 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct tetriminos_piece
{
    int coordinates[8];
    char letter;
    int     x_offset;//column
    int     y_offset;//row
    struct tetriminos_piece *next;

}   tet_item;

int tetrimino_count(char *input);
int count_adjacent_hashes(char *input);
int validate_tetriminos_shape(char *input, int size);
int shift_coordinates_rc(int *coords, int r, int c);
int align_coordinates_top_left(int *coords);
int get_coordinates(char *input, int inSize, int *coords);
void free_tet_list(tet_item *list);
tet_item *new_tet_item(char *input, int inSize, char letter);
tet_item *make_tet_list(char *input, int inSize);
tet_item *parser(char *filename);


#endif

