/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:54:23 by atamraka          #+#    #+#             */
/*   Updated: 2022/03/16 09:26:22 by atamraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

/*typedef struct    s_piece
{
    int                blockcoords[8];
    char            pieceletter;
    int                x_point;
    int                y_point;
    struct s_piece    *next;
}                t_piece;*/

typedef struct tetriminos_piece
{
    int coordinates[8];
    char letter;
    int     x_offset;//column
    int     y_offset;//row
    struct tetriminos_piece *next;

}   tet_item;

typedef struct    s_map
{
    char        **array;
}                t_map;

#endif
