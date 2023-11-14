/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:16:06 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 22:07:28 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_shorts_index(t_data *data, int ind1, int ind2, int ind3)
{
	t_value	*current;

	data->top_head = 0;
	data->top_tail = 1;
	current = data->s_b_head;
	while (current)
	{
		if (current->index == ind1 || current->index == ind2
			|| current->index == ind3)
			break ;
		data->top_head++;
		current = current->next;
	}
	current = data->s_b_tail;
	while (current)
	{
		if (current->index == ind1 || current->index == ind2
			|| current->index == ind3)
			break ;
		data->top_tail++;
		current = current->prev;
	}
}

void	phase_2_helper(t_data *data)
{
	if (data->s_a_head->index == data->ind_list->i - 2)
		move_ra(data);
	else if (data->s_a_tail->val != (data->ind_list->i - 2)
		&& data->s_a_head->val > data->s_a_head->next->val)
		move_sa(data);
}
