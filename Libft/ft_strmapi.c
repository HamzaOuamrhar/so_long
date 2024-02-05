/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:49:29 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 15:28:10 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == 0 || f == 0)
		return (0);
	while (s[i])
		i++;
	r = (char *)malloc((i + 1) * sizeof(char));
	if (r == 0)
		return (0);
	while (j < i)
	{
		r[j] = f(j, s[j]);
		j++;
	}
	r[j] = '\0';
	return (r);
}
