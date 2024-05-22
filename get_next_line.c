#include "get_next_line.h"

static char	*read_to_line(int fd, char *buff, char *remembrance)
{
	int	bytes_read;
	char *temp;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!remembrance)
			remembrance = ft_strdup("");
		temp = remembrance;
		remembrance = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (remembrance);
}

static char	*set_remembrance(char *line_raw)
{
	char	*remembrance;
	size_t 	i;

	i = 0;
	while (line_raw[i] != '\n' && line_raw[i] != '\0')
		i++;
	remembrance = ft_substr(line_raw, i + 1, (ft_strlen(line_raw) - i));
	if (i == ft_strlen(line_raw))
	{
		free(remembrance);
		remembrance = NULL;
	}
	if (line_raw[i] != '\0')
		line_raw[i + 1] = '\0';
	return (remembrance);
}

char	*get_next_line(int fd)
{
	static char	*remembrance;
	char	*buff;
	char 	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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