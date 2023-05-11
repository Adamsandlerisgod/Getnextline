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
#include <string.h>

char    *ft_free_join(char *res, char *buffer)
{
        // char    *temp;
        char    *yeet;
        // temp = ft_strjoin(res, buffer);char* str_concat(char* str1, char* str2) {
        size_t str1_len;
        
        str1_len = strlen(res);
        yeet = (char*)malloc(str1_len + BUFFER_SIZE + 1);
        ft_memcpy(yeet, res, str1_len);
        ft_memcpy(yeet + str1_len, buffer, BUFFER_SIZE + 1);
       
        // ft_strlen(res(res, buffer, BUFFER_SIZE);
        free(buffer);
        free(res);
        return (yeet);
}
char    *read_file(int fd, char *res)
{
        int bytes_read;
        char *buffer;

        if (!res || res[0] == '\0')
        {
            res = malloc(1);
            res[0] = '\0';
        }
        bytes_read = 1;
        while (bytes_read > 0)
        {
            buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            buffer[bytes_read] = 0;
            if (bytes_read < 0)
            {
                free(buffer);
                free(res);
                return (NULL);
            }
            // if (buffer[0] != '\n')
            //     buffer[bytes_read] = '\0';
            if (bytes_read > 0)
            {
                if (ft_strchr(buffer, '\n'))
                {    
                    res = ft_free_join(res, buffer);
                    buffer = NULL;
                    break;
                }
                else
                {
                    res = ft_free_join(res, buffer);
                    buffer = NULL;
                }
            }
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
        res = malloc((i + 1) * sizeof(char));
        i = 0;
        while (buffer[i - 1] != '\n' && buffer[i] != '\0')
        {
            res[i] = buffer[i];
            i++;
        }
        res[i] = 0;
        // if (buffer[i] == '\n')
        //     res[i] = '\n';
        // if (buffer[i] == '\0')
        //     res[i] = '\0';
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
        line = malloc((ft_strlen(buffer, '\0') - i + 2) * sizeof(char));
        j = 0;
        while (buffer[i])
            line[j++] = buffer[i++];
        line[j] = 0;
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
