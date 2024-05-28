/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-r <csilva-r@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:38:47 by csilva-r          #+#    #+#             */
/*   Updated: 2024/05/26 22:45:38 by csilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static char	*read_to_line(int fd, char *buff, char *remembrance)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!remembrance)
			remembrance = ft_strdup("");
		temp = remembrance;
		remembrance = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(remembrance, '\n'))
			break ;
	}
	return (remembrance);
}

static char	*set_remembrance(char *line_raw)
{
	char	*remembrance;
	size_t	i;

	i = 0;
	while (line_raw[i] != '\n' && line_raw[i] != '\0')
		i++;
	remembrance = ft_substr(line_raw, i + 1, ft_strlen(line_raw) - i);
	if (i == ft_strlen(line_raw))
	{
		free(remembrance);
		remembrance = NULL;
	}
	if (line_raw[i] != '\0')
		line_raw[i + 1] = '\0';
	return (remembrance);
}

char	*get_next_line1(int fd)
{
	static char	*remembrance;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		if (remembrance) {
			free(remembrance);
			remembrance = NULL;
		}
		return (NULL);
	}
	buff = (char *)malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = read_to_line(fd, buff, remembrance);
	free(buff);
	buff = NULL;
	if (!line || ft_strlen(line) < 1)
	{
		free(line);
		return (NULL);
	}
	remembrance = set_remembrance(line);
	return (line);
}
*/

char	*get_next_line(int fd)
{
	static char 	*remembrance;
	char		*buff;
	char 		*line;
	int		bytes_read;
	size_t 		i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (remembrance)
		{
			free(remembrance);
			remembrance = NULL;
		}
		return (NULL);
	}

	buff = malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);

	if (!remembrance)
		remembrance = ft_strdup("");

	bytes_read = 1;
	while (!ft_strchr(remembrance, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(remembrance);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		line = remembrance;
		remembrance = ft_strjoin(line, buff);
		free(line);
	}
	free(buff);

	// extract from remembrance
	line = ft_strdup(remembrance);
	free(remembrance);
	remembrance = NULL;

	if (!line || ft_strlen(line) < 1)
	{
		free(line);
		return (NULL);
	}

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;

	remembrance = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (i == ft_strlen(line))
	{
		free(remembrance);
		remembrance = NULL;
	}
	if (line[i] != '\0')
		line[i + 1] = '\0';

	return (line);
}
