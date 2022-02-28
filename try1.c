/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:58:52 by atamraka          #+#    #+#             */
/*   Updated: 2022/02/28 08:56:41 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
# include <stdio.h> //needs to remove this
//# include "libft/libft.h"

void read_line(char **)
int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
		printf("usage: ....\n"); // proper terms needs to be written, printf
	fd = open(argv[1], O_RDONLY, 0644);
	printf("FD: %d\n", fd); // needs to remove this
	if (fd < 0)
		printf("error\n");// printf
	else
	{
		//error check

		read_line(char **)

	}
	close (fd);
	//system("leaks a.out"); //needs to remove this
	return (1);
}
