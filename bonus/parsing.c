/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 08:59:05 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/19 08:12:37 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	int_overflow_c(char *s, int sign, t_data *data)
{
	if (sign == -1)
	{
		if (ft_strncmp(s, "2147483648", 12) <= 0 && ft_strlen(s) == 10)
			return ;
	}
	else
	{
		if (ft_strncmp(s, "2147483647", 12) <= 0 && ft_strlen(s) == 10)
			return ;
	}
	to_exit_c(data, "||ERROR||\nArgument out of bounds!\n");
}

void	pars_checker_c(t_data *data, char *str)
{
	char	*s;
	int		sign;

	s = str;
	sign = 0;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		s++;
	}
	if (!s[0])
		to_exit_c(data, "error");
	while (*s == '0')
		s++;
	if (str_finder(s, "0123456789") != (int)ft_strlen(s))
		to_exit_c(data, "||ERROR||\nInvalid arguments!\n");
	if (ft_strlen(s) >= 10)
		int_overflow_c(s, sign, data);
}

void	double_checker_c(t_data *data)
{
	t_value	*current;
	t_value	*comp;

	current = data->s_a_head;
	while (current->next)
	{
		comp = current->next;
		while (comp)
		{
			if (current->val == comp->val)
				to_exit_c(data, "||ERROR||\nCannot contain doubles!\n");
			comp = comp->next;
		}
		current = current->next;
	}
}

void	ft_parsing_c(char **av, t_data *data)
{
	int	i;

	i = 0;
	data->s_a_nbr = 0;
	data->s_b_nbr = 0;
	while (av[++i])
	{
		pars_checker_c(data, av[i]);
		add_list_c(data, ft_atoi(av[i]));
	}
	double_checker_c(data);
}
