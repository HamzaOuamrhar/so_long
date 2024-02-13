/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:02:13 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/12 22:33:23 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	valide_position(int i, int j, t_mlx_data *data)
{
	if (data->map_array[j][i+1] ==  '0' && data->map_array[j][i-1] == '0'
		&& (data->map_array[j+1][i] == '0' || data->map_array[j-1][i] == 0))
			return (1);
	return (0);
}

void	get_enemy_pos(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(data->map_array[j])
	{
		i = 0;
		while(data->map_array[j][i])
		{
			if (data->map_array[j][i] == '0')
			{
				if (valide_position(i, j, data))
				{
					data->ex = i;
					data->ey = j;
					return ;
				}
			}
			i++;
		}
		j++;
	}
}

void	put_enemy(t_mlx_data *data)
{
	if (data->e_dir == 0)
	{
		if (data->map_array_copy[data->ey][data->ex + 1] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->enm, (data->ex + 1) * 48, data->ey * 48);
			mlx_put_image_to_window(data->mlx, data->window, data->back_img, data->ex * 48, data->ey * 48);
			data->ex += 1;
		}
		else
			data->e_dir = 1;
	}
	else
	{
		if (data->map_array_copy[data->ey][data->ex - 1] != '1')
		{
			mlx_put_image_to_window(data->mlx, data->window, data->enm_l, (data->ex - 1) * 48, data->ey * 48);
			mlx_put_image_to_window(data->mlx, data->window, data->back_img, data->ex * 48, data->ey * 48);
			data->ex -= 1;
		}
		else
			data->e_dir = 0;
	}
}