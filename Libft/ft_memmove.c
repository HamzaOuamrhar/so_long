/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:32:11 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 18:54:15 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	n;

	n = 0;
	if (src > dst)
	{
		while (n < len)
		{
			((unsigned char *)(dst))[n] = ((unsigned char *)src)[n];
			n++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *)(dst))[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
