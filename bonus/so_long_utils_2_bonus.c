/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:37:54 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/12 18:45:25 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	arrays(t_mlx_data *data, int fd, int last, char *map_path)
{
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	data->map_array = map_to_array(fd, last);
	if (!data->map_array)
		return (0);
	close(fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	data->map_array_copy = map_to_array(fd, last);
	if (!data->map_array_copy)
		return (0);
	close(fd);
	data->height = last;
	data->width = ft_strlen(data->map_array[0]) - 1;
	return (1);
}

int	close_window_handler(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	freeing(data);
	free_images(data);
	exit(0);
}

void	initialize_vars(t_mlx_data *data)
{
	data->xp = 0;
	data->yp = 0;
	data->height = 0;
	data->width = 0;
	data->collectibles = 0;
	data->collected = 0;
	data->moves = 0;
	data->e = 0;
	data->p = 0;
	data->dir = 0;
	data->flag = 0;
	data->timing = 0;
}
