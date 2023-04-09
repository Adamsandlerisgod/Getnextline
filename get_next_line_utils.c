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

#include "get_next_line.h"

int found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	 current = ft_lst_get_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	} 
	return (0);
}

t_list	ft_lst_get_last(t_list *stash)
{
	t_list	*current;

	while (current && current->next)
		current = current->next;
	return (current);
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				j++;
				break;
			}
			i++;
			j++;
		}
		stash = stash->next; 
	}
	*line = malloc(sizeof(char) * (j + 1)); 
	if (*line == NULL)
		return;
}

int		ft_strlen(const char *string)
{
	int	len;

	len = 0;
	while(*(str++))
		len++;
	return (len);
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}	
