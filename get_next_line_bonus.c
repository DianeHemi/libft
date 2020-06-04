/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:48:50 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/03 18:48:52 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_n(char *buffer, char c)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *buffer, int *nb_letters)
{
	char		buf[BUFFER_SIZE + 1];
	int			n;
	char		*tmp;

	n = 0;
	while ((n == 0) && (*nb_letters = read(fd, buf, BUFFER_SIZE)))
	{
		buf[*nb_letters] = '\0';
		if (!buffer)
			buffer = ft_strndup(buf, ft_strlen(buf));
		else
		{
			tmp = buffer;
			buffer = ft_strjoin(buffer, buf);
			free(tmp);
		}
		if (find_n(buffer, '\n'))
			n = 1;
	}
	return (buffer);
}

char	*get_line(char *buffer, char **line, int *res)
{
	int			i;
	char		*tmp;

	i = 0;
	if (buffer)
	{
		while (buffer[i] != '\0' && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			*line = ft_strndup(buffer, i);
			tmp = buffer;
			buffer = copy_after_n(buffer, i + 1);
			free(tmp);
			*res = 1;
			return (buffer);
		}
		else
		{
			*line = ft_strndup(buffer, ft_strlen(buffer));
			return (buffer);
		}
	}
	*line = ft_strndup("", 0);
	return (buffer);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer[2560];
	int			res;
	int			nb_letters;

	res = 0;
	if (read(fd, buffer[fd], 0) < 0 || BUFFER_SIZE < 1 || !line || fd < 1)
		return (-1);
	buffer[fd] = read_file(fd, buffer[fd], &nb_letters);
	if (nb_letters < 0)
		return (-1);
	buffer[fd] = get_line(buffer[fd], line, &res);
	if (res == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	return (1);
}
