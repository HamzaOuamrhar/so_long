/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:11:33 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 16:18:56 by houamrha         ###   ########.fr       */
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
	int e;
	int p;
}	mlx_data;

void print_moves_count(mlx_data *data);
int valide_extension(char *path);
int check_map(int fd, char *map_path, int *last, mlx_data *data);
char **map_to_array(int fd, int last);
void freeing(mlx_data data);
int validate_path(mlx_data data, int xp, int yp);
int open_and_validate_images(mlx_data *data);
void free_images(mlx_data *data);
int last_line(int fd);
int	check_last_line(size_t len, char *s);
int	check_chars(int i, mlx_data *data, char *s, int first);
int	multiple_checks(int first, int last, size_t len, char *s);

#endif