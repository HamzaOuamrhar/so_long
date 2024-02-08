/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:36:03 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/08 22:23:34 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(int fd, char *map_path, int *last, mlx_data *data)
{
	int		e;
	int		p;
	size_t	i;
	int		first;
	char	*s;
	size_t	len;

	e = 0;
	p = 0;
	i = 0;
	*last = last_line(fd);
	first = 2;
	fd = open(map_path, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return (close(fd), 0);
	len = ft_strlen(s);
	while (i < len - 2)
	{
		if (s[i] != '1')
			return (close(fd), 0);
		i++;
	}
	free(s);
	s = get_next_line(fd);
	while (s)
	{
		if (first != *last)
			if (len != ft_strlen(s))
				return (free(s), close(fd), 0);
		i = 0;
		if (first == *last)
			if (!check_last_line(len, s))
				return (free(s), close(fd), 0);
		if (s[0] != '1' || s[len - 2] != '1')
			return (free(s), close(fd), 0);
		while (i < len - 2)
		{
			if (s[i] == 'C')
				data->collectibles += 1;
			else if (s[i] == 'E')
				e += 1;
			else if (s[i] == 'P')
			{
				p += 1;
				data->xp = i;
				data->yp = first - 1;
			}
			else if (s[i] != '0' && s[i] != '1')
				return (free(s), close(fd), 0);
			i++;
		}
		first++;
		free(s);
		s = get_next_line(fd);
	}
	if (!data->collectibles || e != 1 || p != 1)
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
