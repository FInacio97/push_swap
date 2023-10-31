/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:35:20 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/31 19:52:32 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	relative_slicer_helper(t_value *node)
{
	t_value *current;

	current = node;
	while (current)
	{
		current->slice_rel = -1;
		current = current->next;
	}
}

void	relative_slicer(t_data *data)
{
	int i;
	int rel_index;
	t_value *min;
	t_value *current;

	i = data->s_a_nbr + 1;
	rel_index = 0;
	current = data->s_a_head;
	relative_slicer_helper(current);
	while (--i)
	{
		min = data->s_a_head;
		while (min && min->slice_rel != -1)
			min = min->next;
		current = min->next;
		while (current)
		{
			if (current->val < min->val && current->slice_rel == -1)
				min = current;
			current = current->next;
		}
		min->slice_rel = rel_index / 2;
		rel_index++;
	}
}

void	relative_slicer_s5(t_data *data)
{
	int i;
	int rel_index;
	t_value *min;
	t_value *current;

	i = data->s_a_nbr + 1;
	rel_index = 0;
	current = data->s_a_head;
	relative_slicer_helper(current);
	while (--i)
	{
		min = data->s_a_head;
		while (min && min->slice_rel != -1)
			min = min->next;
		current = min->next;
		while (current)
		{
			if (current->val < min->val && current->slice_rel == -1)
				min = current;
			current = current->next;
		}
		min->slice_rel = rel_index;
		rel_index++;
	}
}

void	rotate_to_short(t_data *data)
{
	if (data->short_head < data->short_tail)
	{
		while (data->short_head--)
			move_ra(data);
	}
	else
	{
		while (data->short_tail--)
			move_rra(data);
	}
	move_pb(data);
}

t_moves	*new_moves_list(char *move, char *list)
{
	t_moves *node;

	node = (t_moves *)malloc(sizeof(t_moves));
	if (!node)
		return (NULL);
	node->move = ft_strdup(move);
	node->list = ft_strdup(list);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	move_to_list(t_data *data, char *move, char *list)
{
	t_moves *temp;

	temp = data->m_l_tail;
	data->m_l_tail = new_moves_list(move, list);
	data->moves_nbr++;
	ft_printf("moves: %d\n", data->moves_nbr);
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

void	print_moves(t_moves *head)
{
	t_moves *current;

	current = head;
	while (current)
	{
		ft_printf("%s%s\n", current->move, current->list);
		current = current->next;
	}
}

void	print_moves_reverse(t_moves *head)// 	ONLY FOR TESTING
{
	t_moves *current;

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

void	optimizer_helper(t_data *data)
{
	t_moves *node;

	if (data->moves_nbr == 1)
	{
		moves_node_deleter(data->m_l_tail);
	data->m_l_tail = NULL;
		data->moves_nbr--;
		data->moves_flag = 0;
		return ;
	}
	node = data->m_l_tail;
	data->m_l_tail = node->prev;
	data->m_l_tail->next = NULL;
	moves_node_deleter(node);
	data->moves_nbr--;
}

void	optimizer(t_data *data)
{
	t_moves *node;

	node = data->m_l_tail;
	if (ft_strncmp(node->prev->move, node->move, 2) == 0
		&& ft_strncmp(node->prev->list, node->list, 1)	!= 0
		&& str_finder(node->prev->list,"ab") == 1)
	{
		node->prev->list[0] = node->prev->move[0];
		node->prev->next = NULL;
		data->m_l_tail = node->prev;
		moves_node_deleter(node);
		data->moves_nbr--;
		if (data->m_l_tail->list[0] == 'p')
			optimizer_helper(data);
	}
}

/*
	tail -> sa
	ra <- sa -> NULL	
*/