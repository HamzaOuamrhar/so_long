/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:11:33 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/08 21:14:03 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "../Libft/libft.h"

typedef struct mlx_data
{
	void *mlx;
	void *window;
	char **map_array;
	char **map_array_copy;
	void *player_img;
	void *wall_img;
	void *col_img;
	void *back_img;
	void *exit_img;
	int xp;
	int yp;
	int collectibles;
	int collected;
	int moves;
}	mlx_data;

#endif