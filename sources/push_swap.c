/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:20:00 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/23 17:08:46 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_data data;

	if (ac > 1)
	{
		data.s_a_head = NULL;
		data.s_a_tail = NULL;
		data.s_b_head = NULL;
		data.s_b_tail = NULL;
		ft_parsing(av, &data);
		
		get_shorts(&data, 1, -1);
		ft_printf("short head: %d\nshort tail: %d\n", data.short_head, data.short_tail);
		// ft_printf("Posição do 3: %d\n", get_index(data.s_a_head, 3));
		// sort_4(&data);
		// ft_printf("moves to slice 1: %d\n", get_short_slice_tail(data.s_a_tail, 1, -1));
		print_list(data.s_a_head);

		to_exit(&data, "Program terminated with success!\n");
	}
}