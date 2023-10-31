/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:12:14 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/31 10:47:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_data *data)
{
	t_value	*temp;

	if (data->s_a_nbr < 2)
		return ;
	temp = data->s_a_head->next;
	data->s_a_head->prev = temp;
	data->s_a_head->next = temp->next;
	temp->prev = NULL;
	if (data->s_a_nbr > 2)
		temp->next->prev = data->s_a_head;
	temp->next = data->s_a_head;
	data->s_a_head = temp;
	move_to_list(data, "s", "a");
}

void	move_pa(t_data *data)
{
	t_value	*temp;

	if (data->s_b_nbr > 0)
	{
		temp = data->s_b_head->next;
		if (data->s_a_nbr == 0)
		{
			data->s_b_head->next = NULL;
			data->s_a_tail = data->s_b_head;
		}
		else
		{
			data->s_b_head->next = data->s_a_head;
			data->s_a_head->prev = data->s_b_head;
		}
		data->s_a_head = data->s_b_head;
		if (data->s_b_nbr > 1)
		{
			data->s_b_head = temp;
			data->s_b_head->prev = NULL;
		}
		else
			data->s_b_head = NULL;
		data->s_b_nbr--;
		data->s_a_nbr++;
	}
	move_to_list(data, "p", "a");
}

void	move_ra(t_data *data)
{
	t_value	*temp;

	if (data->s_a_nbr > 1)
	{
		temp = data->s_a_head;
		data->s_a_head = data->s_a_head->next;
		data->s_a_head->prev = NULL;
		data->s_a_tail->next = temp;
		temp->prev = data->s_a_tail;
		temp->next = NULL;
		data->s_a_tail = temp;
	}
	move_to_list(data, "r", "a");
}

void	move_rra(t_data *data)
{
	t_value	*temp;

	if (data->s_a_nbr > 1)
	{
		temp = data->s_a_tail;
		data->s_a_tail = data->s_a_tail->prev;
		data->s_a_tail->next = NULL;
		temp->prev = NULL;
		temp->next = data->s_a_head;
		data->s_a_head->prev = temp;
		data->s_a_head = temp;
	}
	move_to_list(data, "rr", "a");
}
