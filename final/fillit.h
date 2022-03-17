/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:34:52 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/17 11:56:31 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h" //needs to set up proper paths
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

typedef struct    s_map
{
    char        **array;
}                t_map;

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
void	solver(t_piece *piecelist);
int	determine_map(t_map *map, t_piece *piece, int mapsize);
int	inside(t_piece *piece, int mapsize, char axis);
void	placing(t_piece *piece, t_map *map, char letter);
int	overlap(t_map *map, t_piece *piece);
void	free_map(t_map *map, int mapsize);
void	printer(t_map *map, int size);
size_t	piece_counter(t_piece *piecelist);
t_map	*create_new_map(int mapsize);
int	count_map_size(int n);

#endif

