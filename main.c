#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char 	*line;

	fd = open("test_2.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		write(1, line, 1);
	}

	return (0);
}
