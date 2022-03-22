/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:56:51 by egaliber          #+#    #+#             */
/*   Updated: 2022/03/22 10:12:58 by atamraka         ###   ########.fr       */
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
	return (mapsize);
}

t_map	*create_new_map(int mapsize)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *) malloc(sizeof(t_map));
	map->array = (char **)malloc(sizeof(char *) * mapsize);
	while (i < mapsize)
	{
		map->array[i] = ft_strnew(mapsize);
		ft_memset(map->array[i], '.', mapsize);
		i++;
	}
	return (map);
}

<<<<<<< HEAD
<<<<<<< HEAD
size_t	piece_counter(tet_item *piecelist)
=======
size_t	piece_counter(t_item *piecelist)
>>>>>>> 481786d95acd3a78b7f08f77dfa2d88e21e59636
=======
size_t	piece_counter(t_item *piecelist)
>>>>>>> refs/remotes/origin/main
{
	size_t	counter;

	counter = 0;
	while (piecelist)
	{
<<<<<<< HEAD
			piecelist = piecelist->next;
			count++;
=======
			piecelist = piecelist -> next;
			counter++;
>>>>>>> refs/remotes/origin/main
	}
	return (counter);
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
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
//	ft_memdel((void **)&(map->array[i]));
	ft_memdel((void **)&map);
}
