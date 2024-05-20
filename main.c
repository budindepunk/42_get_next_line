#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char 	*line;

	fd = open("test_2.txt", O_RDONLY);

	// line = get_next_line(fd);
	// printf("%s\n", line);
	// while (line != NULL)
	// {
	// 	printf("%s\n", line);
	// 	line = get_next_line(fd);
	// }

	int i = 0;
	while (i < 15)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("%s\n", line);
		else
			printf("end of file\n");
		i++;
	}
	free (line);
	return (0);
}

// problem when i keep calling gnl after file ended