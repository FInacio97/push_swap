/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:14:02 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 22:22:17 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		ft_parsing_c(av, &data);
		moves_checker(&data);
		order_check_c(&data);
	}
}
