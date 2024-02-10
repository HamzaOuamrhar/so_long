/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:40:34 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/10 16:22:58 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_mlx_data *data)
{
	if (data->back_img)
		mlx_destroy_image(data->mlx, data->back_img);
	if (data->col_img)
		mlx_destroy_image(data->mlx, data->col_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
}


int	open_and_validate_images(t_mlx_data *data)
{
	int	k;
	int	z;

	data->back_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/square.xpm", &k, &z);
	data->col_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/C.xpm", &k, &z);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/E.xpm", &k, &z);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/P.xpm", &k, &z);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/1.xpm", &k, &z);
	if (!data->back_img || !data->col_img || !data->exit_img
		|| !data->player_img || !data->wall_img)
		return (free_images(data), 0);
	return (1);
}
