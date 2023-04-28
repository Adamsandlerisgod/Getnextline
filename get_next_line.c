/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:33:32 by whendrik          #+#    #+#             */
/*   Updated: 2023/04/23 13:33:34 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char    *ft_free_join(char *res, char *buffer)
{
        char    *temp;

        temp = ft_strjoin(res, buffer);
        free(buffer);
        return (temp);
}
char    *read_file(int fd, char *res)
{
        int bytes_read;
        char *buffer;
        
        if (!res)
            res = ft_calloc(1,1);
        printf("read_file test");
        buffer = ft_calloc((BUFFER_SIZE + 1),  sizeof(char));
        if (!buffer)
        {
            free(buffer);
            return (NULL);
        }
        bytes_read = 1;
        while (bytes_read > 0)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read < 0)
            {
                free(buffer);
                return (NULL);
            }
            buffer[bytes_read] = '\0';
            if (bytes_read >= 0)
                res = ft_free_join(res, buffer);
            if (ft_strchr(buffer, '\n'))
                break;
        }
        if (buffer)
            free(buffer);
        return (res);
}

char    *ft_line(char *buffer)
{
        char    *res;
        int     i;

        if (!buffer)
            return (NULL);
        i = ft_strlen(buffer, '\n');
        res = ft_calloc(i + 1, sizeof(char));
        i = 0;
        while (buffer[i] != '\n' && buffer[i])
        {
            res[i] = buffer[i];
            i++;
        }
        if (buffer[i] == '\n' || buffer[i] == '\0')
            res[i] = '\n';
        return (res);
}
/* after ft_line buffer still remains as the entirety of the result obtained from
read_file including what comes after the newline or '\0' character.
*/
char   *next_line(char *buffer)
{
        int     i;
        char    *line;
        int     j;

        i = ft_strlen(buffer, '\n');
        printf("next_line pre-copy buffer: %s", buffer);
        if (buffer[i] == '\0' || buffer[i] == '\n')
        {
            free(buffer);
            return (NULL);
        }
        line = ft_calloc((ft_strlen(buffer, '\0') - i + 2), sizeof(char));
        j = 0;
        while (buffer[i])
            line[j++] = buffer[i++];
        printf("next_line post copy buffer: %s", buffer);
        printf("next_line post copy line: %s", buffer);
        free(buffer);
        return (line);
}

char    *get_next_line(int fd)
{
        static char  *buffer;
        char    *line;

        printf("test start");
        if(fd < 0|| BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
            return (NULL);
        buffer = read_file(fd, buffer);
        //if (!buffer)
        //    return (NULL);
        /*line = ft_line(buffer);
        buffer = next_line(buffer);
        return (line);*/
        line = "Your moms a bitch";
        return (line);
}
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
//	int		fd1;
//	int		fd2;
	int		fd3;
//	fd1 = open("tests/test.txt", O_RDONLY);
//	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 2)
	{
		/*line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		*/line = get_next_line(fd3);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		i++;
	}
//	close(fd1);
//	close(fd2);
	close(fd3);
	return (0);
}