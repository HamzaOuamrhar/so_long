/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:38:47 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/08 21:40:04 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int last_line(int fd)
{
	int i = 0;
	char *s = get_next_line(fd);
	while(s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char **map_to_array(int fd, int last)
{
	int i = 0;
	char **map_array = (char **)malloc((last + 1) * sizeof(char *));
	if (!map_array)
		return (NULL);
	while(i < last)
	{
		map_array[i] = get_next_line(fd);
		i++;
	}
	map_array[i] = NULL;
	return(map_array);
}

void free_array(char **array)
{
	int i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void freeing(mlx_data data)
{
	free_array(data.map_array);
	free_array(data.map_array_copy);
}

void print_moves_count(mlx_data *data)
{
	data->moves += 1;
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
}