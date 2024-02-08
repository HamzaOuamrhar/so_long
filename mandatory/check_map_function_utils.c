/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_function_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:15:27 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/08 22:25:34 by houamrha         ###   ########.fr       */
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
