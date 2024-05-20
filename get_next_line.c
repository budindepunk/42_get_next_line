#include "get_next_line.h"

/*
--
int open (const char* path, int flags [, int mode ]);
flags (O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, O_EXCL)
returns an int or -1 on fail
--
ssize_t read(int fd, void *buf, size_t nbyte);
reads nbyte bytes of data from fd into buf
returns num of bytes read or -1 on fail
--
static variables
are only initialized once and live until the end of the program
automatically initialized as 0
only can be initialized with a constan literal
*/

char	*get_next_line(int fd)
{
	static char	*remembrance;
	char	*buff;
	char	*line_raw;
	char	*line;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (ft_strchr(remembrance, '\n') == NULL)
		line_raw = read_to_line(fd, buff, remembrance);
	else	
		ft_strlcpy(line_raw, remembrance, ft_strlen(remembrance));
	free(buff);
	buff = NULL;
	if (!line_raw)
		return (NULL);
	line = extract_line(line_raw, remembrance); /////
	return (line);
}

// read into "line" one buffer-length at a time.
// stop when the read segment contains \n or \0
char	*read_to_line(int fd, char *buff, const char *remembrance)
{
	char	*line_raw;
	size_t	bytes_read;

	bytes_read = 0;
	line_raw = "";
	if (ft_strlen(remembrance) > 0)
		line_raw = ft_strjoin(line_raw, remembrance);
	// and now i append to line one bufferito at a time
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line_raw = ft_strjoin(line_raw, buff);
		buff[BUFFER_SIZE] = '\0';
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	line_raw[]
	return (line_raw);
}

char	*extract_line(char *line_raw, char *remembrance)
{
	char	*line;
	int		i;

	i = 0;
	while (line_raw[i] != '\n' || line_raw[i] != '\0')
		i++;
	
}
// scan the line and take the remainder 
// return (remembrance)