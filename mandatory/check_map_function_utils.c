/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_function_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:15:27 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/09 16:19:51 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_last_line(size_t len, char *s)
{
	size_t	i;

	i = 0;
	if (len - 1 != ft_strlen(s))
		return (0);
	while (i < len - 1)
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_chars(int i, mlx_data *data, char *s, int first)
{
	if (s[i] == 'C')
		data->collectibles += 1;
	else if (s[i] == 'E')
		data->e += 1;
	else if (s[i] == 'P')
	{
		data->p += 1;
		data->xp = i;
		data->yp = first - 1;
	}
	else if (s[i] != '0' && s[i] != '1')
		return (0);
	return (1);
}

int	multiple_checks(int first, int last, size_t len, char *s)
{
	if (first != last)
		if (len != ft_strlen(s))
			return (0);
	if (first == last)
		if (!check_last_line(len, s))
			return (0);
	if (s[0] != '1' || s[len - 2] != '1')
		return (0);
	return (1);
}
