/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:56:51 by egaliber          #+#    #+#             */
/*   Updated: 2022/03/14 11:48:54 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
laskee sqaure root ja laskee aloituskoon mapin_koolle.
*/

int	count_map_size(int n)
{
	int	mapsize;

	mapsize = 2;
	while (mapsize * mapsize < n)
	{
		mapsize++;
	}
	return (map_size);
}

t_map	*create_new_map(int mapsize)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *) malloc(sizeof)(t_map));
	map->array = (char **)malloc(sizeof(char *) * mapsize);
	while (i < mapsize)
	{
		map->array[i] = ft_strnew(mapsize);
		ft_memset(map->array[i], '.', mapsize);
		i++;
	}
	return (map);
}

size_t	piece_counter(t_piece *piecelist)
{
	size_t	counter;

	counter = 0;
	while (piecelist)
	{
			piecelist = piecelist -> next;
			count++;
	}
	return (count);
}

void	printer(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int mapsize)
{
	int	i;

	i = 0;
	while (i < mapsize)
	{
		ft_memdel(void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array[i]));
	ft_memdel((void **)&map);
}
