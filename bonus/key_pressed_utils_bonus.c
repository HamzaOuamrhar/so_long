/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:37 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/11 20:41:43 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keys(int key, t_mlx_data *data)
{
	if (key == 126)
	{
		if (data->map_array[data->yp - 1][data->xp] == '1')
			return (0);
		up_key(data);
	}
	else if (key == 125)
	{
		if (data->map_array[data->yp + 1][data->xp] == '1')
			return (0);
		down_key(data);
	}
	else if (key == 124)
	{
		if (data->map_array[data->yp][data->xp + 1] == '1')
			return (0);
		right_key(data);
	}
	else if (key == 123)
	{
		if (data->map_array[data->yp][data->xp - 1] == '1')
			return (0);
		left_key(data);
	}
	return (1);
}

void	up_key(t_mlx_data *data)
{
	print_moves_count(data);
	if (data->dir == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_img,
			(data->xp * 48), (data->yp * 48 - 48));
	else
		mlx_put_image_to_window(data->mlx, data->window, data->player_l_img,
			(data->xp * 48), (data->yp * 48 - 48));
	mlx_put_image_to_window(data->mlx, data->window, data->back_img,
		(data->xp * 48), (data->yp * 48));
	if (data->map_array[data->yp][data->xp] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit_img,
			(data->xp * 48), (data->yp * 48));
	data->yp -= 1;
}

void	down_key(t_mlx_data *data)
{
	print_moves_count(data);
	if (data->dir == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_img,
			(data->xp * 48), (data->yp * 48 + 48));
	else
		mlx_put_image_to_window(data->mlx, data->window, data->player_l_img,
			(data->xp * 48), (data->yp * 48 + 48));
	mlx_put_image_to_window(data->mlx, data->window, data->back_img,
		(data->xp * 48), (data->yp * 48));
	if (data->map_array[data->yp][data->xp] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit_img,
			(data->xp * 48), (data->yp * 48));
	data->yp += 1;
}

void	right_key(t_mlx_data *data)
{
	data->dir = 0;
	print_moves_count(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player_img,
		(data->xp * 48 + 48), (data->yp * 48));
	mlx_put_image_to_window(data->mlx, data->window, data->back_img,
		(data->xp * 48), (data->yp * 48));
	if (data->map_array[data->yp][data->xp] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit_img,
			(data->xp * 48), (data->yp * 48));
	data->xp += 1;
}

void	left_key(t_mlx_data *data)
{
	data->dir = 1;
	print_moves_count(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player_l_img,
		(data->xp * 48 - 48), (data->yp * 48));
	mlx_put_image_to_window(data->mlx, data->window, data->back_img,
		(data->xp * 48), (data->yp * 48));
	if (data->map_array[data->yp][data->xp] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit_img,
			(data->xp * 48), (data->yp * 48));
	data->xp -= 1;
}
