/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:20:02 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 15:48:21 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hystack, const char *needle, size_t len)
{
	size_t	i;

	if (hystack == NULL && len == 0)
		return (NULL);
	if (*needle == '\0' || (hystack == needle))
		return ((char *)hystack);
	while (*hystack && len > 0)
	{
		i = 0;
		while (hystack[i] == needle[i] && hystack[i] && i < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)hystack);
		hystack++;
		len--;
	}
	return (NULL);
}
