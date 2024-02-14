/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:13:22 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/14 16:11:38 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animate_player_r(t_mlx_data *data)
{
	if (data->map_array[data->yp][data->xp] != 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->back_img,
			data->xp * 48, data->yp * 48);
	if (data->flag == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_img,
			data->xp * 48, data->yp * 48);
	else if (data->flag == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->p1,
			data->xp * 48, data->yp * 48);
	else if (data->flag == 2)
		mlx_put_image_to_window(data->mlx, data->window, data->p2,
			data->xp * 48, data->yp * 48);
	else if (data->flag == 3)
		mlx_put_image_to_window(data->mlx, data->window, data->p3,
			data->xp * 48, data->yp * 48);
}

void	animate_player_l(t_mlx_data *data)
{
	if (data->map_array[data->yp][data->xp] != 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->back_img,
			data->xp * 48, data->yp * 48);
	if (data->flag == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_l_img,
			data->xp * 48, data->yp * 48);
	else if (data->flag == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->p1_l,
			data->xp * 48, data->yp * 48);
	else if (data->flag == 2)
		mlx_put_image_to_window(data->mlx, data->window, data->p2_l,
			data->xp * 48, data->yp * 48);
	else if (data->flag == 3)
		mlx_put_image_to_window(data->mlx, data->window, data->p3_l,
			data->xp * 48, data->yp * 48);
}

int	animate_player(t_mlx_data *data)
{
	if (data->ex == data->xp && data->ey == data->yp)
	{
		cleaning(data);
		write(1, "Game Over!", 10);
		exit(1);
	}
	if (data->timing2 == 5000)
		put_enemy(data);
	if (data->timing == 1000)
	{
		if (data->dir == 0)
			animate_player_r(data);
		else
			animate_player_l(data);
		if (data->flag == 3)
			data->flag = 0;
		else
			data->flag += 1;
		data->timing = 0;
	}
	data->timing += 1;
	data->timing2 += 1;
	return (0);
}
