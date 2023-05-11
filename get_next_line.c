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

        if (!res || res[0] == '\0')
            res = ft_calloc(1,1);
        bytes_read = 1;
        while (bytes_read > 0)
        {
            buffer = ft_calloc((BUFFER_SIZE + 1) , sizeof(char));
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read < 0)
            {
                free(buffer);
                free(res);
                return (NULL);
            }
            if (buffer[0] != '\n')
                buffer[bytes_read] = '\0';
            if (bytes_read > 0)
            {
                res = ft_free_join(res, buffer);
                buffer = NULL;
            }
            if (ft_strchr(res, '\n'))
                break;
        }
        if ((buffer != NULL && buffer[0] != '\n' 
            && buffer[bytes_read] != '\n'))
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
        res = ft_calloc((i + 1) , sizeof(char));
        i = 0;
        while (buffer[i] != '\n' && buffer[i] != '\0')
        {
            res[i] = buffer[i];
            i++;
        }
        if (buffer[i] == '\n')
            res[i] = '\n';
        if (buffer[i] == '\0')
            res[i] = '\0';
        return (res);
}

char   *next_line(char *buffer)
{
        int     i;
        char    *line;
        int     j;

        i = ft_strlen(buffer, '\n');
        if (buffer[i] == '\0') 
        {
            free(buffer);
            return (NULL);
        }
        line = ft_calloc((ft_strlen(buffer, '\0') - i + 2), sizeof(char));
        j = 0;
        while (buffer[i])
            line[j++] = buffer[i++];
        free(buffer);
        return (line);
}

char    *get_next_line(int fd)
{
        static char  *buffer;
        char    *line;

        if(fd < 0|| BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
            return (NULL);
        buffer = read_file(fd, buffer);
        if (!buffer)
           return (NULL);
        if (buffer[0] == '\0')
        {
           free(buffer); 
           buffer = NULL;
           return (NULL);
        }
        line = ft_line(buffer);
        buffer = next_line(buffer);
        return (line);
}
