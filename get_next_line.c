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

// char *conditionator(char **res, char **buffer, int b_r)
// {
//     if (b_r < 0)
//     {
//         free(*buffer);
//         free(*res);
//         return (NULL);
//     }

//     if (b_r > 0)
//     {
// 		if (ft_strchr(*buffer, '\n'))
//         {    
//             *res = ft_free_join(*res, *buffer);
//             *buffer = NULL;
//             return (*res);
//         }
//         else
//         {
//             *res = ft_free_join(*res, *buffer);
//             *buffer = NULL;
//         }
//     }
//     return (*res);
// 	// return (NULL);
// }

char *read_file_helper(char *res, char *buffer, int b_r)
{
    if (b_r > 0)
	{
		if (ft_strchr(buffer, '\n'))
		{
			res = ft_free_join(res, buffer);
			buffer = NULL;
			return res;
		}
		else
		{
			res = ft_free_join(res, buffer);
			buffer = NULL;
			return res;
		}
	}
	else if (buffer && buffer[0] != '\n' && buffer[b_r] != '\n')
	{
		free(buffer);
		return res;
	}
	return res;
}
char	*read_file(int fd, char *res)
{
	int		b_r;
	char	*buffer;

	if (!res || res[0] == '\0')
	{
		res = specific_calloc(1, 1);
	}
	b_r = 1;
	while (b_r > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		// printf("readcount: %d\n", b_r);
		b_r = read(fd, buffer, BUFFER_SIZE);
		buffer[b_r] = 0;
		// if (res == NULL)
		// 	return NULL;
		if (b_r < 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		res = read_file_helper(res, buffer, b_r);
		if (ft_strchr(res, '\n'))
			return res;
	}
	return (res);
}
// char	*read_file(int fd, char *res)
// {
// 	int		b_r;
// 	char	*buffer;

// 	// buffer = NULL;
// 	if (!res || res[0] == '\0')
// 	{
// 		res = malloc(1);
// 		res[0] = '\0';
// 	}
// 	b_r = 1;
// 	while (b_r > 0)
// 	{
// 		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 		b_r = read(fd, buffer, BUFFER_SIZE);
// 		buffer[b_r] = 0;
// 		// conditionator(&res, &buffer, b_r);
// 		if (res == NULL)
// 			return NULL;
// 		if (b_r < 0)
// 		{
// 			free(buffer);
// 			free(res);
// 			return (NULL);
// 		}
// 		if (b_r > 0)
// 		{
// 			if (ft_strchr(buffer, '\n'))
// 			{
// 				res = ft_free_join(res, buffer);
// 				buffer = NULL;
// 				break ;
// 			}
// 			else
// 			{
// 				res = ft_free_join(res, buffer);
// 				buffer = NULL;
// 			}
// 		}
// 	}
// 	if ((buffer && buffer[0] != '\n' && buffer[b_r] != '\n'))
// 		free(buffer);
// 	return (res);
// }

char	*ft_line(char *buffer)
{
	char	*res;
	int		i;
	int		len;
	// int		blen;

	// // printf("see%s", buffer);
	if (!buffer)
		return (NULL);
	len = ft_strlen(buffer, '\n');
	// blen = ft_strlen(buffer, '\0');
	// // printf(">%d = %d\n", len, blen);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = 0;
	// ft_memcpy(res, buffer, len + 1);
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

	if (buffer[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	// res[i] = '\n';
	res[i] = 0;
	// printf("res end of ft_line: %s", res);
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
// 	// // printf(">%d = %d\n", len, blen);
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
	while (buffer[i])
		line[j++] = buffer[i++];
	// ft_memcpy(line, buffer, BUFFER_SIZE + 1);
	// printf("line after memcpy in nextline: %s", buffer);
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
	// // printf("buff before ft_line: %s \n", buffer);
	line = ft_line(buffer);
	// printf("buffer after ft_line: %s", buffer);	
	buffer = next_line(buffer);
	//  printf("buff:%s", buffer);
	return (line);
}
