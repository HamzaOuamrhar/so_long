/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:11:33 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 18:00:59 by houamrha         ###   ########.fr       */
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

typedef struct rendering_pos
{
	int i;
	int j;
	int f;
	int l;
}	rendering_pos;

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
int	check_chars(mlx_data *data, char *s, int first, size_t len);
int	multiple_checks(int first, int last, size_t len, char *s);
int	check_first_line(char *s, size_t *len);
void	put_images(mlx_data *data, rendering_pos rp);
void	up_key(mlx_data *data);
void	down_key(mlx_data *data);
void	right_key(mlx_data *data);
void	left_key(mlx_data *data);
int	handle_keys(int key, mlx_data *data);

#endif