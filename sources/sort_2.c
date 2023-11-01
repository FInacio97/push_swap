/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:37:56 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/01 09:10:47 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *data)
{
	if (order_check(data) == 1)
		move_sa(data);
}

void	sort_3(t_data *data)
{
	relative_slicer(data);
	if (data->s_a_head->slice_rel == 1)
		move_ra(data);
	else if (data->s_a_head->next->slice_rel == 1)
		move_rra(data);
	if (order_check(data) == 1)
		move_sa(data);
}

void	sort_4_helper(t_data *data, int *swap_check)
{
	move_sa(data);
	if (*swap_check-- == 1)
		move_sb(data);
}

void	sort_4(t_data *data, int swap_check)
{
	// ft_printf("=============\n===SORT 4===\n=============\n\n");
	// ft_printf("swap check: %d\n", swap_check);
	relative_slicer(data);
	//check the exceptions like 0132 or 01234 or 1034 and maybe others... 1342
	
	// print_list(data->s_a_head);
	// Its fucking up with 4132 x-x-
	get_relative_shorts(data, 1, -1, 1);
	//place both highest values on top
	if ((data->short_head == 0 && data->short_tail == 2)//		x-x-	s/r		-xx-
		|| (data->short_head == 1 && data->short_tail == 1))//	-x-x	s/rr	x--x
		sort_4_helper(data, &swap_check);
	else if (data->short_head == 2 && data->short_tail == 1)//	--xx	rr/rr	x--x
		move_rra(data);
	get_relative_shorts(data, 1, -1, -1);
	if (data->short_head == 0 && data->short_tail == 1)//		x--x	rr	
		move_rra(data);
	else if (data->short_head == 1 && data->short_tail == 2)//	-xx-	r
		move_ra(data);

	//swap the highest two (the ones on top) if needed
	if (ft_intcmp(data->s_a_head->val, data->s_a_head->next->val) > 0)
		sort_4_helper(data, &swap_check);
	
	//the following move regards the sort 5 algorythm (just in case the median index (of 5) is in the stack b)
	if (data->s_b_nbr == 1 && data->s_b_head->val > data->s_a_tail->val
		&& data->s_b_head->val < data->s_a_head->val)
		{
			move_pa(data);
			move_ra(data);
		}
	//move the highest two, now in the correct order to the bottom
	move_ra(data);
	move_ra(data);

	//swap if needed the two lowest numbers
	if (ft_intcmp(data->s_a_head->val, data->s_a_head->next->val) > 0)
		sort_4_helper(data, &swap_check);
	// print_list(data->s_a_head);
	// ft_printf("=============\n=============\n\n");
}

void	sort_5(t_data *data)
{
	relative_slicer_s5(data);
	get_relative_shorts(data, 0, 2, 4);
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
	sort_4(data, 0);
	if (data->s_b_nbr > 0 && data->s_b_head->slice_rel != 2)
		move_pa(data);
	if (order_check(data) != 0)
	{
		move_ra(data);
	}
}