/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:40:34 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/11 21:28:13 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (data->player_l_img)
		mlx_destroy_image(data->mlx, data->player_l_img);
}

void	free_more_images(t_mlx_data *data)
{
	if (data->enm_l)
		mlx_destroy_image(data->mlx, data->enm_l);
	if (data->p1)
		mlx_destroy_image(data->mlx, data->p1);
	if (data->p2)
		mlx_destroy_image(data->mlx, data->p2);
	if (data->p3)
		mlx_destroy_image(data->mlx, data->p3);
	if (data->p1_l)
		mlx_destroy_image(data->mlx, data->p1_l);
	if (data->p2_l)
		mlx_destroy_image(data->mlx, data->p2_l);
	if (data->p3_l)
		mlx_destroy_image(data->mlx, data->p3_l);
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
	data->player_l_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/p_l.xpm", &k, &z);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/1.xpm", &k, &z);
	data->enm = mlx_xpm_file_to_image(data->mlx,
			"./textures/enm.xpm", &k, &z);
	if (!data->back_img || !data->col_img || !data->exit_img
		|| !data->player_img || !data->wall_img)
		return (0);
	return (1);
}

int	open_more_images(t_mlx_data *data)
{
	int	k;
	int	z;

	data->enm_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/enm_l.xpm", &k, &z);
	data->p1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/p1.xpm", &k, &z);
	data->p2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/p2.xpm", &k, &z);
	data->p3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/p3.xpm", &k, &z);
	data->p1_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/p1_l.xpm", &k, &z);
	data->p2_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/p2_l.xpm", &k, &z);
	data->p3_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/p3_l.xpm", &k, &z);
	if (!data->enm_l || !data->p1 || !data->p2 || !data->p3
		|| !data->p1_l || !data->p2_l || !data->p3_l)
		return (0);
	return (1);
}

int	open_all_images(t_mlx_data *data)
{
	if (!open_and_validate_images(data) || !open_more_images(data))
	{
		free_images(data);
		free_more_images(data);
		return (0);
	}
	return (1);
}
