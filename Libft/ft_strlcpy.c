/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:05:19 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 20:46:59 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (dstsize == 0)
	{
		while (s[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	while (s[i])
		i++;
	return (i);
}
