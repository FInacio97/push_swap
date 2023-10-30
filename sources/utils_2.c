/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:50:57 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/30 18:40:15 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		order_check(t_data *data)
{
	int	i;
	t_value *current;

	i = 0;
	current = data->s_a_head;
	while (current->next)
	{
		if (current->val >= current->next->val)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

int		get_index(t_value *node, int ind)
{
	int	i;
	t_value *current;

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

void	rater(t_data *data)
{
	if (data->s_a_nbr == 4)
		data->rate = 2;
	else if (data->s_a_nbr >= 10)
		data->rate = data->s_a_nbr / 10;
	else
		data->rate = 1;
}

void	get_shorts(t_data *data, int sl1, int sl2)
{
	int i;
	t_value *cur;

	i = -1;
	cur = data->s_a_head;
	while(cur && ++i >= 0)
	{
		if (cur->slice == sl1 || cur->slice == sl2)
		{
			data->short_head = i;
			break ;
		}	
		cur = cur->next;
	}
	i = 0;
	cur = data->s_a_tail;
	while(cur && ++i >= 0)
	{
		if (cur->slice == sl1 || cur->slice == sl2)
		{
			data->short_tail = i;
			break ;
		}
		i++;
		cur = cur->prev;
	}
}

void	get_relative_shorts(t_data *data, int sl1, int sl2, int sl3)
{
	int i;
	t_value *c;

	i = -1;
	c = data->s_a_head;
	while(c && ++i >= 0)
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
	while(c && ++i >= 0)
	{
		if (c->slice_rel == sl1 || c->slice_rel == sl2 || c->slice_rel == sl3)
		{
			data->short_tail = i;
			break ;
		}
		c = c->prev;
	}
}