/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:26:48 by whendrik          #+#    #+#             */
/*   Updated: 2023/04/09 13:20:44 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

void	read_and_stash(t_list **stash, int *red_ptr, int fd) 
/*Uses read to add characters to the stash*/
{
	char *buf;

	while (found_newline(*stash) == 0 && *red_ptr != 0) //stash is referenced as *stash in this bc we're not going to modify it
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); 
		if (buf == NULL)
			return ;
		*red_ptr = (int) read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *red_ptr == 0) || *red_ptr == -1)
		{
			free(buf);
			return;
		}
		buf [*red_ptr] = '\0'; 
		add_to_stash(buf, stash, *red_ptr);
		free(buf);
	}
}

void	add_to_stash(char *buf, t_list **stash, int red)
/*Adds the content of our buffer to the end of our stash*/
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (red + 1));
	if (new_node->content == NULL)
		return;
	i = 0;
	while (buf[i] && i < red)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	if (*stash == NULL)
	{
		*stash = new_node;
		return;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
	return;
}
 
void	extract_linei(t_list *stash, char **line)
/*Extracts all characters from our stash and stores them in our line*/
{
	int		i;
	int		j;

	if (*stash == NULL)
		return;
	generate_line(stash, line);
	if (*line == NULL)
		return;
	while (stash)
	{
		i = 0;
		stash = stash->next;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i];
			i++;
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
/* After extracting line from stash we don't need those characters anymore
	Function clears the stash only so that the characters that have not been
	returned at the end of our gnl remain in our static stash*/
{
	t_list	*clean_node;
	t-list	*last;
	int		i;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return;
	clean_node->next = NULL;
	i = 0;
	last = ft_lst_get_last(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;	
	while (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(last->content) - i) + 1);
	if (clean_node->content == NULL)
		return;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	 
//Get the next line
char	*get_next_line(int fd)
{
	static	t_list	*stash;
	char			*line;
	int				red;
	
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = NULL;
	line = NULL;
	red = 1;
//	1. Read from fd and add to linked list
	read_and_stash(&stash, &red, fd);  
	if (stash == NULL)
		return NULL;
//	2. Extract from stash to Line
	extract_line(stash, &line)
//	3. Clean up stash
	clean_stash(&stash);
}
int	main(void) 
{	
	int	fd;
	char	*line;

	fd = open("testfiles/gnltest", 0_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
