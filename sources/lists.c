/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:31:07 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 21:18:30 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	*new_list(int val)
{
	t_value	*node;

	node = (t_value *)malloc(sizeof(t_value));
	if (!node)
		return (NULL);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	node->index = -1;
	return (node);
}

void	list_deleter(t_value *node)
{
	t_value	*temp;

	while (node)
	{
		temp = node->next;
		free (node);
		node = temp;
	}
}

void	add_list(t_data *data, int val)
{
	t_value	*temp;

	temp = data->s_a_tail;
	data->s_a_tail = new_list(val);
	if (data->s_a_nbr == 0)
	{
		data->s_a_head = data->s_a_tail;
		data->s_a_nbr++;
		return ;
	}
	data->s_a_tail->prev = temp;
	temp->next = data->s_a_tail;
	data->s_a_nbr++;
}

t_moves	*new_moves_list(char *move, char *list)
{
	t_moves	*node;

	node = (t_moves *)malloc(sizeof(t_moves));
	if (!node)
		return (NULL);
	node->move = ft_strdup(move);
	node->list = ft_strdup(list);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
