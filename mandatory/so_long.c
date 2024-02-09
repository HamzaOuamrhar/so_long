/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:12:31 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 17:14:01 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering(mlx_data *data, int width, int height)
{
	rendering_pos	rp;

	rp.i = 0;
	rp.f = 0;
	while (rp.i < height)
	{
		rp.j = 0;
		rp.l = 0;
		while (rp.j < width)
		{
			put_images(data, rp);
			rp.l++;
			rp.j += 48;
		}
		rp.f++;
		rp.i += 48;
	}
}

int key_pressed_handler(int key, mlx_data *data)
{
	if (key == 126)
	{
		if (data->map_array[data->yp - 1][data->xp] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48), (data->yp * 48 - 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		if (data->map_array[data->yp][data->xp] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit_img, (data->xp * 48), (data->yp * 48));
		data->yp -= 1;
	}
	else if (key == 125)
	{
		if (data->map_array[data->yp + 1][data->xp] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48), (data->yp * 48 + 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		if (data->map_array[data->yp][data->xp] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit_img, (data->xp * 48), (data->yp * 48));
		data->yp += 1;
	}
	else if (key == 124)
	{
		if (data->map_array[data->yp][data->xp + 1] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48 + 48), (data->yp * 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		if (data->map_array[data->yp][data->xp] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit_img, (data->xp * 48), (data->yp * 48));
		data->xp += 1;
	}
	else if (key == 123)
	{
		if (data->map_array[data->yp][data->xp - 1] == '1')
			return (1);
		print_moves_count(data);
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48 - 48), (data->yp * 48));
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		if (data->map_array[data->yp][data->xp] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit_img, (data->xp * 48), (data->yp * 48));
		data->xp -= 1;
	}
	else if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	if (data->map_array[data->yp][data->xp] == 'C')
	{
		data->map_array[data->yp][data->xp] = '0';
		data->collected += 1;
		mlx_put_image_to_window(data->mlx, data->window, data->back_img, (data->xp * 48), (data->yp * 48));
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, (data->xp * 48), (data->yp * 48));
		return(1);
	}
	else if (data->map_array[data->yp][data->xp] == 'E')
	{
		if (data->collected == data->collectibles)
		{
			mlx_destroy_window(data->mlx, data->window);
			exit(0);
		}
		else
			return (1);
	}
	return (0);
}

int close_window_handler(mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

int main(int argc, char **argv)
{
	mlx_data data;
	int height;
	size_t width;
	int last;
	if (argc != 2)
		return(perror("Incorrect number of arguments!"), 1);
	char *map_path = argv[1];
	if (!valide_extension(map_path))
		return (perror("Invalid file extension!"), 1);
	int fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(perror("Map file error opening!"), 1);
	if (check_map(fd, map_path, &last, &data) != 1)
		return(perror("Invalid map"), 1);
	fd = open(map_path, O_RDONLY);
	data.map_array = map_to_array(fd, last);
	if (!data.map_array)
		return (close(fd), perror("Malloc error!"), 1);
	close(fd);
	fd = open(map_path, O_RDONLY);
	data.map_array_copy = map_to_array(fd, last);
	if (!data.map_array_copy)
		return(close(fd), freeing(data), perror("Malloc error!"), 1);
	close(fd);
	height = last;
	width = ft_strlen(data.map_array[0]) - 1;
	if (!validate_path(data, data.xp, data.yp))
		return (freeing(data), perror("Path invalid!"), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return(freeing(data), perror("Mlx pointer error!"), 1);
	data.window = mlx_new_window(data.mlx, (width * 48), (height * 48), "so_long");
	if (!data.window)
		return(free(data.mlx), freeing(data), perror("Window error"), 1);
	if (!open_and_validate_images(&data))
		return(free(data.mlx), freeing(data), perror("Asset error!"), 1);
	rendering(&data, (width * 48), (height * 48));
	mlx_hook(data.window, 2, 0, &key_pressed_handler, &data);
	mlx_hook(data.window, 17, 0, &close_window_handler, &data);
	mlx_loop(data.mlx);
	return(free_images(&data), free(data.mlx), freeing(data), 0);
}