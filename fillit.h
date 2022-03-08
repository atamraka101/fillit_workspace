/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:54:23 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/08 11:02:51 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct    s_piece
{
    int                blockcoords[8];
    char            pieceletter;
    int                x_offset;
    int                y_offset;
    struct s_piece    *next;
}                t_piece;

typedef struct    s_map
{
    char        **array;
}                t_map;

#endif
