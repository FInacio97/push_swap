/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:50:57 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/23 17:24:24 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		order_check(t_data *data)
{
	int	i;
	t_value *current;

	i = 0;
	current = data->s_a_head;
	while (current)
	{
		if (current->index != i)
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
	t_value *current;

	i = -1;
	current = data->s_a_head;
	ft_printf("sl1: %d	sl2: %d\n", sl1, sl2);
	while(current && ++i >= 0)
	{
		if (current->slice == sl1 || current->slice == sl2)
		{
			data->short_head = i;
			break ;
		}	
		current = current->next;
	}
	i = 0;
	current = data->s_a_tail;
	while(current && ++i >= 0)
	{
		if (current->slice == sl1 || current->slice == sl2)
		{
			data->short_tail = i;
			break ;
		}
		i++;
		current = current->prev;
	}
}

