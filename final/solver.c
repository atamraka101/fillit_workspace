/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:49:57 by egaliber          #+#    #+#             */
/*   Updated: 2022/03/22 10:10:22 by atamraka         ###   ########.fr       */
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
	x = piece->cooordinates[i] + piece->x_offset;
	y = piece->cooordinates[i + 1] + piece->y_offset;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = piece->cooordinates[i] + piece->x_offset;
		y = piece->cooordinates[i + 1] + piece->y_offset;
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
	while (i <= 6)
	{
		x = piece->cooordinates[i] + piece->x_offset;
		y = piece->cooordinates[i + 1] + piece->y_offset;
		map->array[y][x] = letter;
		i += 2;
	}
}

int	inside(t_item *piece, int mapsize, char axis)
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
	free_map(amp, mapsize);
}
