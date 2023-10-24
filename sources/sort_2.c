/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:37:56 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/23 17:29:46 by fda-estr         ###   ########.fr       */
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
	if (get_index(data->s_a_head, 2) == 1)
	{
		move_ra(data);
		ft_printf("ra\n");
	}
	else if (get_index(data->s_a_head, 2) == 2)
	{
		move_rra(data);
		ft_printf("rra\n");
	}
	if (order_check(data) == 1)
	{
		move_sa(data);
		ft_printf("sa\n");
	}
}

void	sort_4(t_data *data)
{
	//check the exceptions like 0132 or 01234 or 1034 and maybe others...

	get_shorts(data, 1, -1);
	
	//place both highest values on top
	if (data->short_head == 0 && data->short_tail == 2)//		x-x-	s/r		-xx-
		move_sa(data);
	else if (data->short_head == 1 && data->short_tail == 1)//	-x-x	s/rr	x--x
		move_sa(data);
	else if (data->short_head == 2 && data->short_tail == 1)//	--xx	rr/rr	x--x
		move_rra(data);
	get_shorts(data, 1, -1);
	if (data->short_head == 0 && data->short_tail == 1)//		x--x	rr	
		move_rra(data);
	else if (data->short_head == 1 && data->short_tail == 2)//	-xx-	r
		move_ra(data);

	//swap the highest two (the ones on top) if needed
	if (get_index(data->s_a_head, 3) == 0)
		move_sa(data);
	
	//move the highest two, now in the correct order to the bottom
	move_ra(data);
	move_ra(data);

	//swap if needed the two lowest numbers
	if (get_index(data->s_a_head, 1) == 0)
		move_sa(data);
}
