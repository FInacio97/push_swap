/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:33:40 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/30 17:32:18 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*study signals, you can wait for a signal from the the 
sort_6 or/and sort_4 functions to do the sync swap*/
void	sort_6(t_data *data)
{
	relative_slicer(data);
	get_relative_shorts(data, 0, -1, -1);
	rotate_to_short(data);
	move_pb(data);
	get_relative_shorts(data, 0, -1, -1);
	rotate_to_short(data);
	move_pb(data);
	sort_4(data);
	if (data->s_b_head->val < data->s_b_head->next->val)
		move_sb(data);
	move_pa(data);
	move_pa(data);
}

void	sort_7(t_data *data)
{
	relative_slicer(data);
	get_relative_shorts(data, 0, -1, -1);
	rotate_to_short(data);
	move_pb(data);
	get_relative_shorts(data, 0, -1, -1);
	rotate_to_short(data);
	move_pb(data);
	ft_print_both_lists(data);
	sort_5(data);
	if (data->s_b_head->val < data->s_b_head->next->val)
		move_sb(data);
	print_list(data->s_a_head);
	move_pa(data);
	move_pa(data);
}