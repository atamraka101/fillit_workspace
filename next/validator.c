/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:23:42 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/14 12:23:57 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int tetrimino_count(char *input)
{
    int i;
    int hashcount;

    i = 0;
    hashcount = 0;
    while (i <= 20)
    {
        if (input[i] && input[i]) != '.' && input[i] != '#' && input[i] != '\n')
            return (0);
        if ((i % 5) == 4)
        {
            if (input[i] != '\n')
                return (0);
        }
        if (input[i] == '#')
            hashcount++
        i++;
    }
    return (hashcount);
}

int next_to_counter(char *input)
{
    int i;
    int hashcount;

    i = 0;
    hashcount = 0;
    while (i < 19)
    {
        if (input[i] == '#')
        {
            if (i + 1 <= 18 && input[i + 1] == '#')
                hashcount++;
            if (i - 1 >= 0 && input[i - 1] == '#')
                hashcount++;
            if (i + 5 <= 18 && input[i + 5] == '#')
                hashcount++;
            if (i - 5 >= 0 && input[i - 5] == '#')
                hashcount++;
        }
        i++;
    }
    return (hashcount);
}

int validate_tetriminos_shape(char *input, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (tetrimino_count(input[i]) != 4)
            return (0);
        if (next_to_counter(input[i]) != 6 && next_to_counter(input[i]) != 8)
            return (0);
        i += 21;
    }
    return (1);
}