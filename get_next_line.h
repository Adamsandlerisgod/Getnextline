/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:32:31 by whendrik          #+#    #+#             */
/*   Updated: 2023/04/07 16:22:05 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000 
# endif
char	*get_next_line(int fd);

size_t	ft_strlen(char *string, char z);
char	*ft_strjoin(char *str1, char *str2);
void	ft_bzero(void *str, size_t size);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *haystack, int needle);

#endif
