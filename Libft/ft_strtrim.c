/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:55:33 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/14 16:29:30 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	first(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (in_set(s1[i], set))
			i++;
		else
			break ;
	}
	return (i);
}

static int	last(char const *s1, char const *set)
{
	int	i;
	int	f;

	i = ft_strlen(s1);
	f = first(s1, set);
	while (i > f)
	{
		if (in_set(s1[i - 1], set))
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first_i;
	int		last_i;
	char	*r;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	j = 0;
	first_i = first(s1, set);
	last_i = last(s1, set);
	if (first_i > last_i)
		return (ft_strdup(""));
	r = (char *)malloc((last_i - first_i + 1) * sizeof(char));
	if (r == NULL)
		return (0);
	while (first_i < last_i)
	{
		r[j] = s1[first_i];
		first_i++;
		j++;
	}
	r[j] = '\0';
	return (r);
}
