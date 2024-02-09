/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:36:03 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 16:30:37 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(int fd, char *map_path, int *last, mlx_data *data)
{
	size_t	i;
	int		first;
	char	*s;
	size_t	len;

	*last = last_line(fd);
	first = 2;
	fd = open(map_path, O_RDONLY);
	s = get_next_line(fd);
	if (!check_first_line(s, &len))
		return (close(fd), 0);
	s = get_next_line(fd);
	while (s)
	{
		i = 0;
		if (!multiple_checks(first, *last, len, s))
			return (close(fd), free(s), 0);
		while (i < len - 2)
		{
			if (!check_chars(i, data, s, first))
				return (free(s), close(fd), 0);
			i++;
		}
		first++;
		free(s);
		s = get_next_line(fd);
	}
	if (!data->collectibles || data->e != 1 || data->p != 1)
		return (close(fd), 0);
	return (close(fd), 1);
}

char	**fill_map(mlx_data data, int xp, int yp)
{
	if (data.map_array_copy[yp][xp] == '1'
		|| data.map_array_copy[yp][xp] == 'Z')
		return (data.map_array_copy);
	data.map_array_copy[yp][xp] = 'Z';
	fill_map(data, xp, yp - 1);
	fill_map(data, xp, yp + 1);
	fill_map(data, xp - 1, yp);
	fill_map(data, xp + 1, yp);
	return (data.map_array_copy);
}

int	validate_path(mlx_data data, int xp, int yp)
{
	int		x;
	int		y;
	char	**map_array_copy;

	x = 0;
	y = 0;
	map_array_copy = fill_map(data, xp, yp);
	while (map_array_copy[y])
	{
		x = 0;
		while (map_array_copy[y][x])
		{
			if (map_array_copy[y][x] == 'C' || map_array_copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valide_extension(char *path)
{
	int		i;
	int		len;
	char	*p;

	p = path;
	len = ft_strlen(path);
	i = len - 4;
	p += i;
	if (ft_strncmp(p, ".ber", 4) != 0)
		return (0);
	return (1);
}
