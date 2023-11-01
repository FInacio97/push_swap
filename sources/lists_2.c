/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:29:43 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/01 12:11:12 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_list(t_data *data, char *move, char *list)
{
	t_moves	*temp;

	temp = data->m_l_tail;
	data->m_l_tail = new_moves_list(move, list);
	data->moves_nbr++;
	if (data->moves_flag == 0)
	{
		data->moves_flag = 1;
		data->m_l_head = data->m_l_tail;
		return ;
	}
	data->m_l_tail->prev = temp;
	temp->next = data->m_l_tail;
	if (data->moves_nbr > 1)
		optimizer(data);
}

void	moves_node_deleter(t_moves *node)
{
	free (node->move);
	free (node->list);
	free (node);
}

void	list_moves_deleter(t_moves *node)
{
	t_moves	*temp;

	while (node)
	{
		temp = node->next;
		moves_node_deleter(node);
		node = temp;
	}
}

void	print_moves(t_moves *head)
{
	t_moves	*current;

	current = head;
	while (current)
	{
		ft_printf("%s%s\n", current->move, current->list);
		current = current->next;
	}
}

void	print_moves_reverse(t_moves *head)// 	ONLY FOR TESTING
{
	t_moves	*current;

	current = head;
	printf("\nList Reversed\n");
	if (current->next == NULL)
		ft_printf("NULL\n");
	while (current)
	{
		ft_printf("%s", current->move);
		current = current->prev;
	}
	if (current == NULL)
		ft_printf("NULL\n");
}
