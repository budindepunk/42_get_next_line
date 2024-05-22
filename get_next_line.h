#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h> // remove later

char	*get_next_line(int fd);
//char	*read_to_line(int fd, char *buff, const char *remembrance);
//static char	*read_to_line2(int fd, char *buff, char *remembrance);
char	*extract_line(char *line_raw);
//static char	*set_remembrance(char *line_raw);
char	*ft_strchr(const char *s, int c);
//size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif