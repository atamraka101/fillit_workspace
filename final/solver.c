/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:49:57 by egaliber          #+#    #+#             */
/*   Updated: 2022/03/22 10:13:13 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	overlap(t_map *map, t_item *piece)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	/*x = piece->coordinates[i] + piece->x_offset;
	y = piece->coordinates[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->coordinates[i] + piece->x_offset;
		y = piece->coordinates[i + 1] + piece->y_offset;
	}
	return (i != 8);*/
	y = piece->coordinates[i] + piece->y_offset;
	x = piece->coordinates[i + 1] + piece->x_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		y = piece->coordinates[i] + piece->y_offset;
		x = piece->coordinates[i + 1] + piece->x_offset;
	}
	return (i != 8);
}

void	placing(t_item *piece, t_map *map, char letter)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	/*while (i <= 6)
	{
		x = piece->coordinates[i] + piece->x_offset;
		y = piece->coordinates[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}*/
	while (i <= 6)
	{
		y = piece->coordinates[i] + piece->y_offset;
		x = piece->coordinates[i + 1] + piece->x_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}

int	inside(t_item *piece, int mapsize, char axis)
{
	/*if (axis == 'y')
		return (piece->coordinates[1] + piece->y_offset < mapsize
			&& piece->coordinates[3] + piece->y_offset < mapsize
			&& piece->coordinates[5] + piece->y_offset < mapsize
			&& piece->coordinates[7] + piece->y_offset < mapsize);
	else
		return (piece->coordinates[0] + piece->x_offset < mapsize
			&& piece->coordinates[2] + piece->x_offset < mapsize
			&& piece->coordinates[4] + piece->x_offset < mapsize
			&& piece->coordinates[6] + piece->x_offset < mapsize);*/
	if (axis == 'y')
		return (piece->coordinates[0] + piece->y_offset < mapsize
			&& piece->coordinates[2] + piece->y_offset < mapsize
			&& piece->coordinates[4] + piece->y_offset < mapsize
			&& piece->coordinates[6] + piece->y_offset < mapsize);
	else
		return (piece->coordinates[1] + piece->x_offset < mapsize
			&& piece->coordinates[3] + piece->x_offset < mapsize
			&& piece->coordinates[5] + piece->x_offset < mapsize
			&& piece->coordinates[7] + piece->x_offset < mapsize);
}

int	determine_map(t_map *map, t_item *piece, int mapsize)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (inside(piece, mapsize, 'y'))
	{
		while (inside(piece, mapsize, 'x'))
		{
			if (!overlap(map, piece))
			{
				placing(piece, map, piece->letter);
				if (determine_map(map, piece->next, mapsize))
					return (1);
				else
				{
					placing(piece, map, '.');
				}
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

void	solver(t_item *piecelist)
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
	free_map(map, mapsize);
}
