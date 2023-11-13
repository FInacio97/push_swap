/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:20:00 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 21:18:34 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initializer(t_data *data)
{
	data->moves_flag = 0;
	data->moves_nbr = 0;
	data->s_a_head = NULL;
	data->s_a_tail = NULL;
	data->s_b_head = NULL;
	data->s_b_tail = NULL;
	data->m_l_head = NULL;
	data->m_l_tail = NULL;
}

static void	sorter(t_data *data, int ac)
{
	if (ac == 3)
		sort_2(data);
	else if (ac == 4)
		sort_3(data);
	else if (ac == 5)
		sort_4(data, 0);
	else if (ac == 6)
		sort_5(data);
	else if (ac <= 11)
		sort_to_9(data);
	else
		sort_10(data);	
}

int main(int ac, char **av)
{
	t_data data;

	if (ac > 2)
	{
		initializer(&data);
		ft_parsing(av, &data);
		sorter(&data, ac);	
		print_moves(data.m_l_head);
		// ft_printf("Moves: %d\n", data.moves_nbr);
		list_moves_deleter(data.m_l_head);
		// if (order_check(&data) == 0)
		// 	ft_printf("OK\n");
		// else
		// 	ft_printf("||ERROR||\nWrong order!!\n");
		// delete_ind_list(data.ind_list);
		// to_exit(&data, "");
	}
}