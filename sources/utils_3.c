/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:35:20 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/01 12:40:04 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	relative_slicer_helper(t_value *node)
{
	t_value	*current;

	current = node;
	while (current)
	{
		current->slice_rel = -1;
		current = current->next;
	}
}

void	relative_slicer(t_data *data)
{
	int		i;
	int		rel_index;
	t_value	*min;
	t_value	*current;

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
	int		i;
	int		rel_index;
	t_value	*min;
	t_value	*current;

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
