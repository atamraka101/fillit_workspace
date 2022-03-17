/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:34:52 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/17 13:05:45 by egaliber         ###   ########.fr       */
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
	int						coordinates[8];
	char					letter;
	int						x_offset;//column
	int						y_offset;//row
	struct tetriminos_piece	*next;

}				t_item;

typedef struct s_map
{
	char	**array;
}			t_map;

/*validator*/
int			tetrimino_count(char *input);
int			count_adjacent_hashes(char *input);
int			validate_tetriminos_shape(char *input, int size);
/*solver*/
void		solver(t_item *piecelist);
int			determine_map(t_map *map, t_item *piece, int mapsize);
int			inside(t_item *piece, int mapsize, char axis);
void		placing(t_item *piece, t_map *map, char letter);
int			overlap(t_map *map, t_item *piece);
/*shifter*/
int			shift_coordinates_rc(int *coords, int r, int c);
int			align_coordinates_top_left(int *coords);
/*parser*/
int			get_coordinates(char *input, int inSize, int *coords);
void		free_tet_list(t_item *list);
t_item		*new_t_item(char *input, int inSize, char letter);
t_item		*make_tet_list(char *input, int inSize);
t_item		*parser(char *filename);
/*mapper*/
int			count_map_size(int n);
t_map		*create_new_map(int mapsize);
size_t		piece_counter(t_piece *piecelist);
void		printer(t_map *map, int size);
void		free_map(t_map *map, int mapsize);

#endif