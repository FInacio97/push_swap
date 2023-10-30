/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:35:20 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/30 18:41:48 by fda-estr         ###   ########.fr       */
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
}

t_moves	*new_moves_list(char *s)
{
	t_moves *node;

	node = (t_moves *)malloc(sizeof(t_moves));
	if (!node)
		return (NULL);
	node->move = ft_strdup(s);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	move_to_list(t_data *data, char *s)
{
	t_moves *temp;

	ft_printf("\n\n==MOVE==\n");
	ft_print_both_lists(data);
	temp = data->m_l_tail;
	data->m_l_tail = new_moves_list(s);
	if (data->moves_flag == 0)
	{
		data->moves_flag = 1;
		data->m_l_head = data->m_l_tail;
		return ;
	}
	data->m_l_tail->prev = temp;
	temp->next = data->m_l_tail;
}

void	print_moves(t_moves *head)
{
	t_moves *current;

	current = head;
	while (current)
	{
		ft_printf("%s\n", current->move);
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

void	list_moves_deleter(t_moves *node)
{
	t_moves	*temp;

	while (node)
	{
		temp = node->next;
		free (node->move);
		free (node);
		node = temp;
	}
}
