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
#  define BUFFER_SIZE 42 
# endif

char	*get_next_line(int fd);
void	*specific_calloc(size_t count, size_t size);
size_t	ft_strlen(char *string, char z);
char	*ft_free_join(char *res, char *buffer);
char	*ft_strchr(const char *haystack, int needle);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
