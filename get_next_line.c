#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remembrance;
	char	*buff;
	char	*line_raw;

	buff = (char *)malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (remembrance == 0)
		remembrance = "";
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (ft_strchr(remembrance, '\n') == NULL)
		line_raw = read_to_line(fd, buff, remembrance);
	else
	{
		line_raw = (char *)malloc(sizeof(char) * (ft_strlen(remembrance) + 1));
		ft_strlcpy(line_raw, remembrance, ft_strlen(remembrance) + 1);
	}
	free(buff);
	buff = NULL;
	if (!line_raw || ft_strlen(line_raw) < 1)
		return (NULL);
	remembrance = set_remembrance(line_raw);
	return (extract_line(line_raw));
}

char	*read_to_line(int fd, char *buff, const char *remembrance)
{
	char	*line_raw;
	size_t	bytes_read;

	bytes_read = 0;
	line_raw = "";
	if (ft_strlen(remembrance) > 0)
		line_raw = ft_strjoin(line_raw, remembrance);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		line_raw = ft_strjoin(line_raw, buff);
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	return (line_raw);
}

char	*extract_line(char *line_raw)
{
	char	*line;
	size_t		i;

	i = 0;
	while (line_raw[i] != '\n' && line_raw[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(line, line_raw, i + 1);
	return (line);
}

char	*set_remembrance(char *line_raw)
{
	char	*remembrance;
	size_t 	i;

	i = 0;
	while (line_raw[i] != '\n' && line_raw[i] != '\0')
		i++;
	remembrance = (char *)malloc(sizeof(char) * ft_strlen(line_raw) - i);
	ft_strlcpy(remembrance, line_raw + i + 1, ft_strlen(line_raw) - i);
	return (remembrance);
}