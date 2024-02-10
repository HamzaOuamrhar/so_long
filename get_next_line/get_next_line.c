/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:43:45 by houamrha          #+#    #+#             */
/*   Updated: 2024/02/10 15:24:37 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	search(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

static void	shift_buffer(char *buffer)
{
	int	j;
	int	k;
	int	i;

	j = 0;
	k = -1;
	i = ft_strlen_s(buffer);
	while (k++ < i)
		if (buffer[k] == '\n')
			break ;
	if (k == i)
	{
		k = 0;
		while (k < i)
			buffer[k++] = '\0';
	}
	else
	{
		k++;
		while (k < i)
			buffer[j++] = buffer[k++];
		while (j < i)
			buffer[j++] = '\0';
	}
}

char	*set_to_line(char *buffer)
{
	int		j;
	int		i;
	char	*line;

	j = 0;
	if (!buffer)
		return (NULL);
	i = search(buffer);
	if (has_new_line(buffer))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	if (has_new_line(buffer))
		i--;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (has_new_line(buffer))
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*read_data(int fd, char *buffer, ssize_t *l)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (free(buffer), buffer = NULL, NULL);
	*l = 1;
	while (*l > 0 && !has_new_line(buffer))
	{
		*l = read(fd, tmp, BUFFER_SIZE);
		if (*l == 0)
			break ;
		if (*l > 0)
		{
			tmp[(*l)] = '\0';
			buffer = ft_strjoin(buffer, tmp);
		}
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		l;

	l = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX || BUFFER_SIZE >= INT32_MAX
		|| read(fd, NULL, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_data(fd, buffer, &l);
	if (check_for_errors(l, buffer))
		return (free(buffer), buffer = NULL, NULL);
	line = set_to_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, line);
	else
		return (shift_buffer(buffer), line);
}
