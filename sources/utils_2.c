/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:50:57 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/02 10:07:41 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_value *node, int ind)
{
	int		i;
	t_value	*current;

	current = node;
	i = 0;
	while (current)
	{
		if (current->index == ind)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

void	rater(t_data *data)//	Defines how many elements make a slice
{
	if (data->s_a_nbr == 4)
		data->rate = 2;
	else if (data->s_a_nbr >= 10)
		data->rate = data->s_a_nbr / 10;
	else
		data->rate = 1;
}

void	get_relative_shorts(t_data *data, int sl1, int sl2, int sl3)
{
	int		i;
	t_value	*c;

	i = -1;
	c = data->s_a_head;
	while (c && ++i >= 0)
	{
		if (c->slice_rel == sl1 || c->slice_rel == sl2 || c->slice_rel == sl3)
		{
			data->short_head = i;
			break ;
		}
		c = c->next;
	}
	i = 0;
	c = data->s_a_tail;
	while (c && ++i >= 0)
	{
		if (c->slice_rel == sl1 || c->slice_rel == sl2 || c->slice_rel == sl3)
		{
			data->short_tail = i;
			break ;
		}
		c = c->prev;
	}
}

void	optimizer_helper(t_data *data)
{
	t_moves	*node;

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
	t_moves	*node;

	node = data->m_l_tail;
	if (ft_strncmp(node->prev->move, node->move, 2) == 0
		&& ft_strncmp(node->prev->list, node->list, 1) != 0
		&& str_finder(node->prev->list, "ab") == 1)
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
