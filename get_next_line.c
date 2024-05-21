#include "get_next_line.h"

/*
char	*read_to_line(int fd, char *buff, const char *remembrance)
{
	char	*line_raw;
	size_t	bytes_read;

	if (remembrance != NULL && ft_strchr(remembrance, '\n') != NULL)
	{
		line_raw = (char *)malloc(sizeof(char) * (ft_strlen(remembrance) + 1));
		ft_strlcpy(line_raw, remembrance, ft_strlen(remembrance) + 1);
		return (line_raw);
	}

	bytes_read = 0;
	line_raw = (char *)malloc((sizeof(char)));
	line_raw[0] = '\0';
	if (remembrance != NULL && ft_strlen(remembrance) > 0)
		line_raw = ft_strjoin(line_raw, remembrance);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		line_raw = ft_strjoin(line_raw, buff);
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	return (line_raw);
}
*/

static char	*read_to_line(int fd, char *buff, char *remembrance)
{
	int	bytes_read;
	char *temp;

	bytes_read = 1;
	while (bytes_read != '\0')
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
/*
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
*/

// i'd like us to go through the logic here. maybe write it down in human language
static char	*set_remembrance(char *line_raw)
{
	char	*remembrance;
	size_t 	i;

	i = 0;
	while (line_raw[i] != '\n' && line_raw[i] != '\0')
		i++;
	remembrance = ft_substr(line_raw, i + 1, ft_strlen(line_raw) - i);
	if (i == ft_strlen(line_raw))
	{
		free(remembrance);
		remembrance = NULL;
	}
	line_raw[i + 1] = '\0';
	return (remembrance);
}

char	*get_next_line(int fd)
{
	static char	*remembrance;
	char	*buff;
//	char	*line_raw;
	char 	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = (char *)malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = read_to_line(fd, buff, remembrance);
	free(buff);
	buff = NULL;
//	if (remembrance != NULL)
//		free(remembrance);
	if (!line|| ft_strlen(line) < 1)
	{
		free(line);
		return (NULL);
	}
	remembrance = set_remembrance(line);
//	line = extract_line(line_raw);
//	free(line_raw);
	return (line);
}