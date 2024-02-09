/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:40:34 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 21:59:04 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_mlx_data *data)
{
	mlx_destroy_image(data->back_img, data->mlx);
	mlx_destroy_image(data->col_img, data->mlx);
	mlx_destroy_image(data->exit_img, data->mlx);
	mlx_destroy_image(data->player_img, data->mlx);
	mlx_destroy_image(data->wall_img, data->mlx);
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
