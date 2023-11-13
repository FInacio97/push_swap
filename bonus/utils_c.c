/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:59:18 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/13 22:20:13 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	order_check_c(t_data *data)
{
	t_value	*current;

	current = data->s_a_head;
	if (data->s_b_nbr)
		to_exit_c(data, "KO");
	while (current->next)
	{
		if (current->val > current->next->val)
			to_exit_c(data, "KO");
		current = current->next;
	}
	to_exit_c(data, "OK");
}

void	to_exit_c(t_data *data, char *s)
{
	if (*s)
		ft_printf("%s\n", s);
	if (data->s_a_head)
		list_deleter_c(data->s_a_head);
	if (data->s_b_head)
		list_deleter_c(data->s_b_head);
	exit (0);
}
