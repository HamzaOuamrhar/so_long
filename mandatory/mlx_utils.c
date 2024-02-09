/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:59:04 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 17:07:26 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(mlx_data *data, rendering_pos rp)
{
	mlx_put_image_to_window(data->mlx, data->window,
		data->back_img, rp.j, rp.i);
	if (data->map_array[rp.f][rp.l] == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->wall_img, rp.j, rp.i);
	else if (data->map_array[rp.f][rp.l] == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->col_img, rp.j, rp.i);
	else if (data->map_array[rp.f][rp.l] == 'P')
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_img, rp.j, rp.i);
	else if (data->map_array[rp.f][rp.l] == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->exit_img, rp.j, rp.i);
	else
		mlx_put_image_to_window(data->mlx, data->window,
			data->back_img, rp.j, rp.i);
}
