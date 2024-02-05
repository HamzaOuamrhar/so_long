/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:11:00 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 20:46:41 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*d;
	const char		*s;
	size_t			i;
	size_t			j;

	if (dstsize == 0)
		return (ft_strlen(src));
	d = dst;
	s = src;
	i = 0;
	j = 0;
	while (i < dstsize && d[i])
		i++;
	while (src[j] && i + j < dstsize - 1)
	{
		d[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		d[i + j] = '\0';
	return (i + ft_strlen(src));
}
