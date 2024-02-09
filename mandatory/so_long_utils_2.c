/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:37:54 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 21:59:58 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	exit(0);
}
