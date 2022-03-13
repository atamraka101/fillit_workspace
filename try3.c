/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:24:59 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/12 13:55:50 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h" // remove lifbt.a from libft file
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>

void validate_tetriminos_shape(char *buf, int bufLen);

int main(int argc, char *argv[])
{
	int fd;
	char buff[545];
	int buff_size;
	int i;
	int hash;
	int dot;
	int n_line;

	hash = 0;
	dot = 0;
	n_line = 0;
	i = 0;
	if (argc != 2)
    {
		//ft_putstr("usage: ....\n");
		printf("usage: ....\n");
        return (1);
    }

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	else
	{
		buff_size = read(fd, buff, 545);
		close (fd);
		if (buff_size < 19 || buff_size > 544)
			return (0);
		buff[buff_size] = '\0'; //# and . counter check for extras
		while (buff[i] != '\0')
		{
			// Process one shape at a time
			// 20 bytes represents a shape and 21 bytes should be shape separator
			validate_tetrimino_shape(&buff[i], 21);
			i += 21;
		}
		/*while (buff[i] != '\0') // matrix size
		{
			if (buff[i] == '#')
			{
				buff[i] = 1;
				hash++;
			}
			else if (buff[i] == '.')
			{
				buff[i] = 0;
				dot++;
			}
			else if (buff[i] == '\n')
			{
				buff[i] = '\n';
				n_line++;
			}
			else
				ft_putstr("error\n");
				return (NULL);
			i++;
		}
	}
	if (hash != 4 || dot != 12 || n_line != 4)
		return (1);
	transfer_given_to4x4(&buff[0], buff_size);*/
	}
	return (1);
}

void validate_tetriminos_shape(char *buf, int bufLen)
{
	int i;
	i = 0;
	while (i < bufLen)
	{
		printf("%c,", buf[i]);
		i++;
	}
}

/*
void transfer_given_to4x4(char **buff, int buff_size)
{
	int i;
	int count;
	count = 0;
	i = 0;
	while (buff[i] != 1)
		i++;
		count++;
	if (count <= 3)

	else if (count <= 8)

	else if (count <= 13)

	else if (count <= 18)

	int j;
	j = 0;
	while ( j < 4)
	{
		while (buff[i] != 1)
		{
			count++;
			i++;
		}

	}

	/*if (count - 1 == 1 || count + 1 == 1 || \
		count - 5 == 1 || count + 5 == 1)*/

/*}

void check_1position(char **buff, int buff_size)
{
	int i;
	int j;
	int o_count;
	int n_count;

	int count_one[4];
	int count_newline[5];
	i = 0;
	j = 0;
	o_count = 0;
	n_count = 0;
	while (buff[i] != '\0')
	{
			if (buff[i] == 1)
			{
				count_one[o_count] = i;
				o_count++;
			}
			if (buff[i + 1] == '\n')
			{
				count_newline[n_count] = i + 1;
				n_count++;
				i++;
			}
		i++;
	}

	int i; i = 0;
	int j;

	while (buff[i] != '\0')
	{
		j = 0;
		while (buff[i] != '\n')
		{
			j++;
		}

		count_newline[z] = j;

		i++;
	}

	/*i = 0;
	while (buff + i != 1)
		i++;
	j = i + 1;
	while (buff + j != 1)
		j++;
	k = j + 1;
	while (buff + k != 1)
		k++;
	l = k + 1;
	while (buff + l != 1)
		l++;
	transfer_in4x4grid(&buff[0], i, j, k, l);

	if (i < 4)
	{
		if (i < 4 && j < 4)
		if (j < 4 && k < 4 && l < 4)


	}

	if (i < 9)

	if (i < 14)

	if (i < 19)*/


/*

transfer_in4x4grid

check_with_presets
*/
