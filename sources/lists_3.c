/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:16:37 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 21:20:28 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index	*new_ind_list(int index)
{
	t_index	*node;

	node = (t_index *)malloc(sizeof(t_index));
	node->i = index;
	node->next = NULL;
	return (node);
}

void	add_ind_list(t_data *data, t_index *node)
{
	t_index	*current;

	current = data->ind_list;
	while (current->next)
		current = current->next;
	current->next = node;
}

void	print_ind_list(t_data *data)
{
	t_index	*current;

	current = data->ind_list;
	while (current)
	{
		ft_printf("%d\t", current->i);
		current = current->next;
	}
	ft_printf("\n");
}

void	delete_ind_list(t_index *node)
{
	t_index	*temp;

	while (node)
	{
		temp = node->next;
		free (node);
		node = temp;
	}
}

void	delete_ind_node(t_data *data, t_index *node)
{
	t_index	*current;

	if (node == data->ind_list)
		data->ind_list = node->next;
	else
	{
		current = data->ind_list;
		while (current->next != node)
			current = current->next;
		current->next = node->next;
	}
	free (node);
}
