#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*read_line;
	int		fd;

	fd = open("teste.txt", O_RDONLY);
	do
	{
		read_line = get_next_line(fd);
		if (!read_line)
			break ;
		printf("%s", read_line);
		free(read_line);
	} while (read_line);
	close(fd);
	return (0);
}
