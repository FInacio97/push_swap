/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:58:18 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 22:03:56 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_next_slice(t_data *data, int *i)
{
	if (data->s_b_nbr % (2 * data->rate) == 0)
		*i += 2;
}

						/*THE CAVEMAN WAY*/
	/*Keeps rotating in one direction and pushes the desired elements*/
void	phase_1(t_data *data)
{
	int	i;

	i = 0;
	while (data->s_a_nbr >= 6)
	{
		if (data->s_a_head->slice == i)
		{
			move_pb(data);
			check_next_slice(data, &i);
		}
		else if (data->s_a_head->slice == i + 1)
		{
			move_pb(data);
			move_rb(data);
			check_next_slice(data, &i);
		}
		else
			move_ra(data);
	}
}

				/*THE CAVEMAN 3.0*/
	/*Compares the distances between the three largest elements*/
void	phase_2_aux(t_data *data)
{
	if (data->s_b_nbr >= 1)
		phase_2_helper(data);
	get_shorts_index(data, data->ind_list->i, data->ind_list->i - 1,
		data->ind_list->i - 2);
	rotate_to_top(data);
	if (data->s_a_head->val > data->s_a_head->next->val)
		move_sa(data);
	if (data->s_a_tail->index == data->ind_list->i - 2)
		move_rra(data);
	delete_ind_node(data, data->ind_list);
	delete_ind_node(data, data->ind_list);
	delete_ind_node(data, data->ind_list);
	if (data->s_a_head->val > data->s_a_head->next->val)
		move_sa(data);
}

void	phase_2(t_data *data)
{
	index_list(data);
	while (data->s_b_nbr)
	{
		get_shorts_index(data, data->ind_list->i,
			data->ind_list->i - 1, data->ind_list->i - 2);
		rotate_to_top(data);
		if (data->s_b_nbr == 0)
		{
			delete_ind_node(data, data->ind_list);
			break ;
		}
		if (data->s_a_head->index == (data->ind_list->i - 2)
			&& data->s_b_nbr >= 2)
			move_ra(data);
		get_shorts_index(data, data->ind_list->i, data->ind_list->i - 1,
			data->ind_list->i - 2);
		rotate_to_top(data);
		if (data->s_b_nbr == 0)
		{
			delete_ind_node(data, data->ind_list);
			break ;
		}
		phase_2_aux(data);
	}
}

void	sort_10(t_data *data)
{
	phase_1(data);
	sort_5(data);
	phase_2(data);
	if (data->s_a_head->val > data->s_a_head->next->val)
		move_sa(data);
}

// void	phase_1(t_data *data)
// {
				/*THE SOPHISTICATED WAY*/
	/*rotates to the closest element of the desired slice*/
// 	int	i;
// 	int	rate;

// 	i = 0;
// 	while (data->s_a_nbr >= 6)
// 	{
// 		rate = data->rate * 2;
// 		while (rate--)
// 		{
// 			get_shorts(data, i, i + 1);
// 			rotate_to_short(data);
// 			if (data->s_b_head->slice == i + 1)
// 				move_rb(data);
// 			if (data->s_a_nbr <= 6)
// 				break ;
// 		}
// 		i += 2;
// 	}
// }

// void	phase_2(t_data *data)
// {
// 					/*THE CAVEMAN WAY*/
// 		/*rotates to the largest element and pushes it*/
// 	index_list(data);
// 	// ft_printf("aqui\n");
// 	// ft_printf("top head: %d\ntop tail: %d\n", 
//data->top_head, data->top_tail);
// 	// ft_print_both_lists(data);
// 	while(data->s_b_nbr)
// 	{
// 		get_tops_index(data);
// 		rotate_to_top(data);
// 		delete_ind_node(data, data->ind_list);
// 	}
// 	// print_ind_list(data);
// 	// ft_printf("top head: %d\ntop tail: %d\n", data->top_head,
// data->top_tail);
// }