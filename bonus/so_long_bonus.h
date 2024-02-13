/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:11:33 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/13 13:32:17 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"

typedef struct t_mlx_data
{
	void	*mlx;
	void	*window;
	char	**map_array;
	char	**map_array_copy;
	void	*player_img;
	void	*player_l_img;
	void	*enm;
	void	*enm_l;
	void	*p1;
	void	*p1_l;
	void	*p2;
	void	*p2_l;
	void	*p3;
	void	*p3_l;
	void	*wall_img;
	void	*col_img;
	void	*back_img;
	void	*exit_img;
	int		xp;
	int		yp;
	int		height;
	size_t	width;
	int		collectibles;
	int		collected;
	int		moves;
	int		e;
	int		p;
	int		dir;
	int		flag;
	int		timing;
	int		timing2;
	int		ex;
	int		ey;
	int		e_dir;
}	t_mlx_data;

typedef struct rendering_pos
{
	int	i;
	int	j;
	int	f;
	int	l;
}	t_rendering_pos;

void	print_moves_count(t_mlx_data *data);
int		valide_extension(char *path);
int		check_map(int fd, char *map_path, int *last, t_mlx_data *data);
char	**map_to_array(int fd, int last);
void	freeing(t_mlx_data *data);
int		validate_path(t_mlx_data data, int xp, int yp);
int		open_and_validate_images(t_mlx_data *data);
void	free_images(t_mlx_data *data);
int		last_line(int fd);
int		check_last_line(size_t len, char *s);
int		check_chars(t_mlx_data *data, char *s, int first, size_t len);
int		multiple_checks(int first, int last, size_t len, char *s);
int		check_first_line(char *s, size_t *len);
void	put_images(t_mlx_data *data, t_rendering_pos rp);
void	up_key(t_mlx_data *data);
void	down_key(t_mlx_data *data);
void	right_key(t_mlx_data *data);
void	left_key(t_mlx_data *data);
int		handle_keys(int key, t_mlx_data *data);
int		arrays(t_mlx_data *data, int fd, int last, char *map_path);
int		close_window_handler(t_mlx_data *data);
int		open_all_images(t_mlx_data *data);
void	initialize_vars(t_mlx_data *data);
int		animate_player(t_mlx_data *data);
void	put_enemy(t_mlx_data *data);
void	get_enemy_pos(t_mlx_data *data);
void	cleaning(t_mlx_data *data);

#endif