/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:38:47 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/11 17:13:02 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	last_line(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**map_to_array(int fd, int last)
{
	int		i;
	char	**map_array;

	i = 0;
	map_array = (char **)malloc((last + 1) * sizeof(char *));
	if (!map_array)
		return (NULL);
	while (i < last)
	{
		map_array[i] = get_next_line(fd);
		i++;
	}
	map_array[i] = NULL;
	return (map_array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	freeing(t_mlx_data *data)
{
	free_array(data->map_array);
	free_array(data->map_array_copy);
}

void	print_moves_count(t_mlx_data *data)
{
	data->moves += 1;
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
}
