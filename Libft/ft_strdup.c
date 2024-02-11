/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:38:37 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 19:09:24 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*copy;
	char		*c;
	const char	*s;
	int			i;

	i = 0;
	s = s1;
	while (*s)
	{
		i++;
		s++;
	}
	copy = (char *)malloc(i * sizeof(char) + 1);
	if (copy == NULL)
		return (0);
	c = copy;
	while (*s1)
	{
		*c = *s1;
		c++;
		s1++;
	}
	*c = '\0';
	return (copy);
}
