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
	char	*line;

	remembrance = NULL;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = read_to_line(fd, buff, remembrance); // stuff happens here
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	return (line);
}

// read into "line" one buffer-length at a time.
// stop when the read segment contains \n or \0
char	*read_to_line(int fd, char *buff, const char *remembrance)
{
	char	*line;

	ft_strlcpy(line, "", 1);
	if (remembrance != NULL)
		line = ft_strjoin(line, remembrance);
	// and now i append to line one bufferito at a time
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff);
		buff[BUFFER_SIZE] = '\0';
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (line);
}

char	*set_remembrance();
// scan the line and take the remainder 
// return (remembrance)