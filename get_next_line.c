#include "get_next_line.h"

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
	line = ft_strdup(remembrance); 	// extract from remembrance
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
