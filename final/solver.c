/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:49:57 by egaliber          #+#    #+#             */
/*   Updated: 2022/03/14 12:33:30 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	overlap(t_map *map, t_piece *piece)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->coords[i] + piece->x_set;
	y = piece->coords[i + 1] + piece->y_set;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->coords[i] + piece->x_set;
		y = piece->coords[i + 1] + piece->y_set;
	}
	return (i != 8);
}

void	placing(t_piece *piece, t_map *map, char letter)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->coords[i] + piece->x_set;
		y = piece->coords[i + 1] + piece->y_set;
		map->array[y][x] = letter;
		i += 2;
	}
}

int	inside(t_piece *piece, int mapsize, char axis)
{
	if (axis == 'y')
		return (piece->blockcoords[1] + piece->y_offset < map_size
			&& piece->blockcoords[3] + piece->y_offset < map_size
			&& piece->blockcoords[5] + piece->y_offset < map_size
			&& piece->blockcoords[7] + piece->y_offset < map_size);
	else
		return (piece->blockcoords[0] + piece->x_offset < map_size
			&& piece->blockcoords[2] + piece->x_offset < map_size
			&& piece->blockcoords[4] + piece->x_offset < map_size
			&& piece->blockcoords[6] + piece->x_offset < map_size);
}

int	determine_map(t_map *map, t_piece *piece, int mapsize)
{
	if (!piece)
		return (1);
	piece->x_set = 0;
	piece->y_set = 0;
	while (inside(piece, mapsize, 'y'))
	{
		while (inside(piece, mapsize, 'x'))
		{
			if (!overlap(map, piece))
			{
				placing(piece, map, piece->pieceletter);
				if (determine_map(map, piece->next, mapsize))
					return (1);
				else
				{
					placing(piece, map, '.');
				}
			}
			piece->x_set++;
		}
		piece->x_set = 0;
		piece->y_set++;
	}
	return (0);
}

void	solver(t_piece *piecelist)
{
	t_map	*map;
	int		mapsize;

	mapsize = count_map_size(piece_counter(piecelist) * 4);
	map = create_new_map(mapsize);
	while (!determine_map(map, piecelist, mapsize))
	{
		free_map(map, mapsize);
		mapsize++;
		map = create_new_map(mapsize);
	}
	printer(map, mapsize);
	free_map(amp, mapsize);
}
