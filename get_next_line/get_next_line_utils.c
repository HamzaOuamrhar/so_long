/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:44:41 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/10 15:24:19 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_s(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	has_new_line(char *buffer)
{
	int	k;

	k = 0;
	if (!buffer)
		return (0);
	while (buffer[k])
	{
		if (buffer[k] == '\n')
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_s(s1) + ft_strlen_s(s2)) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	check_for_errors(ssize_t l, char *buffer)
{
	if (l == -1 || (l == 0 && buffer == NULL)
		|| ((l == 0 && buffer[0] == '\0')))
		return (1);
	return (0);
}
