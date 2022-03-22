/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:34:19 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/17 12:59:07 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	shift_coordinates_rc(int *coords, int r, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		coords[i] += r;
		coords[i + 1] += c;
		i += 2;
	}
	return (1);
}

int	align_coordinates_top_left(int *coords)
{
	int	r_offset;
	int	c_offset;
	int	i;

	r_offset = coords[0];
	c_offset = coords[1];
	i = 2;
	while (i < 8)
	{
		if (r_offset > coords [i])
			r_offset = coords[i];
		if (c_offset > coords[i + 1])
			c_offset = coords[i + 1];
		i += 2;
	}
	r_offset *= -1;
	c_offset *= -1;
	shift_coordinates_rc(coords, r_offset, c_offset);
	return (1);
}
