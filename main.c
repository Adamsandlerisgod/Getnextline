#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
//	int		fd1;
//	int		fd2;
	int		fd3;
//	fd1 = open("tests/test.txt", O_RDONLY);
//	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open(".testertrip/files/alternate_line_nl_no_nl", O_RDONLY);
    line = get_next_line(fd3);
	while (line)
	{
		/*line = get_next_line(fd1);
		// printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		free(line);
		*/
       // printf("Loop %d \n", i);
		// printf("line: %s \n", line);
		free(line);
        line = get_next_line(fd3);
		// printf("line: %s \n", line);
	}
//	close(fd1);
//	close(fd2);
	close(fd3);
	return (0);
}