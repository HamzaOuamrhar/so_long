/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:12:31 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/14 15:41:38 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	rendering(t_mlx_data *data, int width, int height)
{
	t_rendering_pos	rp;

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
	mlx_string_put(data->mlx, data->window, 0, 0, 0xFFFFFF, "Moves:0");
}

void	collecting(t_mlx_data *data)
{
	data->map_array[data->yp][data->xp] = '0';
	data->collected += 1;
	mlx_put_image_to_window(data->mlx, data->window, data->back_img,
		(data->xp * 48), (data->yp * 48));
	if (data->dir == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_img,
			(data->xp * 48), (data->yp * 48));
	else
		mlx_put_image_to_window(data->mlx, data->window, data->player_l_img,
			(data->xp * 48), (data->yp * 48));
}

int	key_pressed_handler(int key, t_mlx_data *data)
{
	if (!handle_keys(key, data))
		return (1);
	if (key == 53)
	{
		cleaning(data);
		exit(0);
	}
	if (data->map_array[data->yp][data->xp] == 'C')
		return (collecting(data), 1);
	else if (data->map_array[data->yp][data->xp] == 'E')
	{
		if (data->collected == data->collectibles)
		{
			cleaning(data);
			write(1, "Congrats!", 10);
			exit(0);
		}
		else
			return (1);
	}
	return (0);
}

int	initialize_game(t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (freeing(data), perror("Error\nMlx pointer error!"), 0);
	data->window = mlx_new_window(data->mlx,
			(data->width * 48), (data->height * 48), "so_long");
	if (!data->window)
		return (freeing(data), perror("Error\nWindow error"), 0);
	if (!open_all_images(data))
		return (freeing(data), perror("Error\nAsset error!"), 0);
	rendering(data, (data->width * 48), (data->height * 48));
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	int			last;
	char		*map_path;
	int			fd;

	if (argc != 2)
		return (perror("Error\nIncorrect number of arguments!"), 1);
	map_path = argv[1];
	if (!valide_extension(map_path))
		return (perror("Error\nInvalid file extension!"), 1);
	initialize_vars(&data);
	fd = open(map_path, O_RDONLY);
	if (!check_map(fd, map_path, &last, &data))
		return (perror("Error\nInvalid map"), 1);
	if (!arrays(&data, fd, last, map_path))
		return (close(fd), freeing(&data), perror("Error\nFd Error!"), 1);
	if (!validate_path(data, data.xp, data.yp))
		return (freeing(&data), perror("Error\nPath invalid!"), 1);
	get_enemy_pos(&data);
	if (!initialize_game(&data))
		exit(1);
	mlx_hook(data.window, 2, 0, &key_pressed_handler, &data);
	mlx_hook(data.window, 17, 0, &close_window_handler, &data);
	mlx_loop_hook(data.mlx, &animate_player, &data);
	mlx_loop(data.mlx);
}
