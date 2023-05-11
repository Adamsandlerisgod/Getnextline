/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:10:02 by whendrik          #+#    #+#             */
/*   Updated: 2023/04/09 13:20:41 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *str, size_t size)
{
		unsigned int	i;
		char	*ptr_str;

		ptr_str = (char *)str;
		i = 0;
		while (i < size)
			ptr_str[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (!str)
		return NULL;
	ft_bzero(str, count * size);
	return (str);	
}

size_t	ft_strlen(char *string, char z)
{
	int	i;

	i = 0;
	if (!string)
		return (i);
	if (z == '\0')
	{
			while (string[i])
				i++;
			return (i);
	}
	else
	{
		while(string[i] != z && string[i])
			i++;
		if (string[i] == z)
			i++;	
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
		unsigned int	i;
		int	j;
		char	*totalstr;
		int	totalsize;

		totalsize = ft_strlen(str1, '\0') + ft_strlen(str2, '\0');
		totalstr = ft_calloc((totalsize + 1) , sizeof(char));
		i = 0;
		if (!totalstr || !str1 || !str2)
			return (NULL);
		while (ft_strlen(str1, '\0') > i)
		{
			totalstr[i] = str1[i];
			i++;
		}
		j = 0;
		while (str2[j])
		{
			totalstr[i] = str2[j];
			i++;
			j++;
		}	
		free(str1);
		return (totalstr);
}

char	*ft_strchr(const char *haystack, int needle)
{
		int		i;
		char	*str;
		
		i = 0;
		str = (char *)haystack;
		while (str[i] != needle && str[i] != '\0')
			i++;
		if (str[i] == needle)
			return (&str[i]);
		else
			return (NULL);
}