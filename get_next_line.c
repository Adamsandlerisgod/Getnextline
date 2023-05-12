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

char	*ft_free_join(char *res, char *buffer)
{
	char	*totalstr;
	size_t	res_len;

	res_len = ft_strlen(res, '\0');
	totalstr = (char *)malloc(res_len + BUFFER_SIZE + 1);
	ft_memcpy(totalstr, res, res_len);
	ft_memcpy(totalstr + res_len, buffer, BUFFER_SIZE + 1);
	free(buffer);
	free(res);
	return (totalstr);
}

char *conditionator(char *res, char **buffer, int bytes_read)
{
    if (bytes_read < 0)
    {
        free(*buffer);
        free(res);
        return (NULL);
    }

    if (bytes_read > 0)
    {
		if (ft_strchr(*buffer, '\n'))
        {    
            res = ft_free_join(res, *buffer);
            *buffer = NULL;
            return (res);
        }
        else
        {
            res = ft_free_join(res, *buffer);
            *buffer = NULL;
        }
    }
    return (res);
}

char	*read_file(int fd, char *res)
{
	int		bytes_read;
	char	*buffer;

	buffer = NULL;
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
		// res = conditionator(res, &buffer, bytes_read);
		// if (res == NULL)
		// 	return NULL;
		if (bytes_read < 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		if (bytes_read > 0)
		{
			if (ft_strchr(buffer, '\n'))
			{
				res = ft_free_join(res, buffer);
				buffer = NULL;
				break ;
			}
			else
			{
				res = ft_free_join(res, buffer);
				buffer = NULL;
			}
		}
	}
	if ((buffer != NULL && buffer[0] != '\n' && buffer[bytes_read] != '\n'))
		free(buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
	char	*res;
	int		i;
	int		len;
	// int		blen;

	printf("see%s", buffer);
	if (!buffer)
		return (NULL);
	len = ft_strlen(buffer, '\n');
	// blen = ft_strlen(buffer, '\0');
	// printf(">%d = %d\n", len, blen);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	// res[len] = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		res[i] = buffer[i];
		i++;
	}
	// if (blen == len)
	// {
	// 	res[i] = '\0';
	// } else

	// if (buffer[i] == '\n')
	// {
	// 	res[i] = '\n';
	// }
	res[i] = '\n';
	res[len] = 0;
	printf("res%s", res);
	return (res);
}
// char	*ft_line(char *buffer)
// {
// 	char	*res;
// 	int		i;
// 	int		len;
// 	int		blen;

// 	if (!buffer)
// 		return (NULL);
// 	len = ft_strlen(buffer, '\n');
// 	// blen = ft_strlen(buffer, '\0');
// 	// printf(">%d = %d\n", len, blen);
// 	res = (char *)malloc((len + 1) * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	res[len] = 0;
// 	i = 0;
// 	while (buffer[i] != '\n' && buffer[i] != '\0')
// 	{
// 		res[i] = buffer[i];
// 		i++;
// 	}
// 	// if (blen == len)
// 	// {
// 	// 	res[i] = '\0';
// 	// } else
// 	if (buffer[i] == '\n')
// 	{
// 		res[i] = '\n';
// 	}
// 	return (res);
// }

char	*next_line(char *buffer)
{
	int		i;
	char	*line;
	int		j;

	i = ft_strlen(buffer, '\n');
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = malloc((ft_strlen(buffer, '\0') - i + 2) * sizeof(char));
	j = 0;
	printf("buff in nextline:%s", buffer);
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = 0;
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
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
	printf("buffber%s", buffer);
	line = ft_line(buffer);
	buffer = next_line(buffer);
	printf("buff:%s", buffer);
	return (line);
}
