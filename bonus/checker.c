/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:14:02 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 21:04:09 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	initializer(t_data *data)
{
	data->s_a_head = NULL;
	data->s_b_head = NULL;
	data->s_a_nbr = 0;
	data->s_b_nbr = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		initializer(&data);
		ft_parsing_c(av, &data);
		moves_checker(&data);
		order_check_c(&data);
		to_exit_c(&data, NULL);
	}
}
