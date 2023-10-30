/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:20:00 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/30 17:35:06 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac > 1)
	{
		data.moves_flag = 0;
		data.s_a_head = NULL;// not sure if all this is necessary...
		data.s_a_tail = NULL;
		data.s_b_head = NULL;
		data.s_b_tail = NULL;//to here...
		data.m_l_head = NULL;
		data.m_l_tail = NULL;
		data.flag = 0;// try to do it without this variable, using the NULLs above
			
		ft_parsing(av, &data);
		
		if (ac == 3)
			sort_2(&data);
		else if (ac == 4)
			sort_3(&data);
		else if (ac == 5)
			sort_4(&data);
		else if (ac == 6)
			sort_5(&data);
		else if (ac == 7)
			sort_6(&data);
		else if (ac == 8)
			sort_7(&data);

		ft_printf("\n\n===SORTED===\n");


		print_list(data.s_a_head);
		print_moves(data.m_l_head);
		list_moves_deleter(data.m_l_head);
		if (order_check(&data) == 0)
			ft_printf("OK\n");
		else
			ft_printf("||ERROR||\nWrong order!!\n");

		to_exit(&data, "Program terminated with success!\n");
	}
}