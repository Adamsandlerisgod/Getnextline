/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:32:31 by whendrik          #+#    #+#             */
/*   Updated: 2023/04/03 16:10:29 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

# define FD_MAX 1000
# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

typedef struct	s_files
{
	char	*buf;
	size_t	size;
	size_t	offset;
	int	stop;
	int	eof;
}				t_files;

size_t	strlen_chr(const char *str, const char c);
char	*ft_recat(char **dst, char *str);
int		read_next(t_files *file, int fd);

#endif
