/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:51:24 by egaliber          #+#    #+#             */
/*   Updated: 2022/03/14 10:45:35 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece	*piecelist;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n")
	}
		if ((piecelist = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solver(piecelist);
	free_piecelist(piecelist);
	return (0);
}
