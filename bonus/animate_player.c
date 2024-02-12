/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:13:22 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/12 17:20:13 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

time_t	get_time()
{
	time_t	t;

	t = time(NULL);
	return (t);
}
void	animate_player_r(t_mlx_data *data)
{
	if (data->flag == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_img, data->xp * 48, data->yp * 48);
	else if (data->flag == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->p1, data->xp * 48, data->yp * 48);
	else if (data->flag == 2)
		mlx_put_image_to_window(data->mlx, data->window, data->p2, data->xp * 48, data->yp * 48);
	else if(data->flag == 3)
		mlx_put_image_to_window(data->mlx, data->window, data->p3, data->xp * 48, data->yp * 48);
}

void	animate_player_l(t_mlx_data *data)
{
	if (data->flag == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_l_img, data->xp * 48, data->yp * 48);
	else if (data->flag == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->p1_l, data->xp * 48, data->yp * 48);
	else if (data->flag == 2)
		mlx_put_image_to_window(data->mlx, data->window, data->p2_l, data->xp * 48, data->yp * 48);
	else if(data->flag == 3)
		mlx_put_image_to_window(data->mlx, data->window, data->p3_l, data->xp * 48, data->yp * 48);
}

int	animate_player(t_mlx_data *data)
{
	static int	ff;

	data->new_time = get_time();
	if (!ff)
	{
		data->old_time = get_time();
		ff = 1;
	}
	if ((data->new_time - data->old_time) == 1)
	{
		data->old_time = get_time();
		if (data->map_array[data->yp][data->xp] != 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->back_img, data->xp * 48, data->yp * 48);
		if (data->dir == 0)
			animate_player_r(data);
		else
			animate_player_l(data);
		if (data->flag == 3)
			data->flag = 0;
		else
			data->flag += 1;
	}
	return (0);
}