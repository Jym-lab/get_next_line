#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int	fd[4];
	char *line;
	fd[0] = open("files/41_with_nl", O_RDONLY);

	printf("%s\n", get_next_line(1000));
	line = get_next_line(fd[0]);
	printf("%s\n", line);
	free(line);

	fd[1] = open("files/42_with_nl", O_RDWR);

	printf("%s\n", get_next_line(1001));
	line = get_next_line(fd[1]);
	printf("%s\n", line);
	free(line);

	fd[2] = open("files/43_with_nl", O_RDWR);

	printf("%s\n", get_next_line(1002));
	line = get_next_line(fd[2]);
	printf("%s\n", line);
	free(line);
	
	printf("%s\n", get_next_line(1003));
	line = get_next_line(fd[0]);
	printf("%s\n", line);
	free(line);

	printf("%s\n", get_next_line(1004));
	line = get_next_line(fd[1]);
	printf("%s\n", line);
	free(line);

	printf("%s\n", get_next_line(1005));
	line = get_next_line(fd[2]);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd[0]);
	printf("%s\n", line);
	line = get_next_line(fd[1]);
	printf("%s\n", line);
	line = get_next_line(fd[2]);
	printf("%s\n", line);

	fd[3] = open("files/nl", O_RDWR);

	printf("%s\n", get_next_line(1006));
	line = get_next_line(fd[3]);
	printf("%d\n", line[0]);
	free(line);
	printf("%s\n", get_next_line(1007));
	line = get_next_line(fd[3]);
	printf("%d\n", line[0]);
}
