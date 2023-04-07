/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:10:02 by whendrik          #+#    #+#             */
/*   Updated: 2023/04/07 22:17:14 by whendrik         ###   ########.fr       */
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

