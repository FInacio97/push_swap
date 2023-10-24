/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:34:25 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/22 23:18:54 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sb(t_data *data)
{
	t_value	*temp;

	if (data->s_b_nbr < 2)
		return ;
	temp = data->s_b_head->next;
	data->s_b_head->prev = temp;
	data->s_b_head->next = temp->next;
	temp->prev = NULL;
	if (data->s_b_nbr > 2)
		temp->next->prev = data->s_b_head;
	temp->next = data->s_b_head;
	data->s_b_head = temp;
}

void	move_pb(t_data *data)
{
	t_value	*temp;	

	if (data->s_a_nbr > 0)
	{
		temp = data->s_a_head->next;
		if (data->s_b_nbr == 0)
		{
			data->s_a_head->next = NULL;
			data->s_b_tail = data->s_a_head;
		}
		else
		{
			data->s_a_head->next = data->s_b_head;
			data->s_b_head->prev = data->s_a_head;
		}
		data->s_b_head = data->s_a_head;
		if (data->s_a_nbr > 1)
		{
			data->s_a_head = temp;
			data->s_a_head->prev = NULL;
		}
		else
			data->s_a_head = NULL;
		data->s_a_nbr--;
		data->s_b_nbr++;
	}
}

void	move_rb(t_data *data)
{
	t_value	*temp;

	if (data->s_b_nbr > 1)
	{
		temp = data->s_b_head;
		data->s_b_head = data->s_b_head->next;
		data->s_b_head->prev = NULL;
		data->s_b_tail->next = temp;
		temp->prev = data->s_b_tail;
		temp->next = NULL;
		data->s_b_tail = temp;
	}
}

void	move_rrb(t_data *data)
{
	t_value	*temp;

	if (data->s_b_nbr > 1)
	{
		temp = data->s_b_tail;
		data->s_b_tail = data->s_b_tail->prev;
		data->s_b_tail->next = NULL;
		temp->prev = NULL;
		temp->next = data->s_b_head;
		data->s_b_head->prev = temp;
		data->s_b_head = temp;
	}
}
