/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:24:38 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/01 12:27:57 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pars_checker(t_data *data, char *str)
{
	char	*s;
	int		sign;

	s = str;
	sign = 0;
	if (s[0] == '-')
	{
		sign = -1;
		s++;
	}
	while (*s == '0')
		s++;
	if (str_finder(s, "0123456789") != (int)ft_strlen(s))
		to_exit(data, "||ERROR||\nInvalid arguments!\n");
	if (sign == -1)
	{
		if (ft_strncmp(s, "2147483648", 11) > 0 && (int)ft_strlen(s) >= 10)
			to_exit(data, "||ERROR||\nArgument out of bounds!\n");
	}
	else
	{
		if (ft_strncmp(s, "2147483647", 11) > 0 && (int)ft_strlen(s) >= 10)
			to_exit(data, "||ERROR||\nArgument out of bounds!\n");
	}
}

void	to_exit(t_data *data, char *s)
{
	if (*s)
		ft_printf("%s\n", s);
	if (data->s_a_head)
		list_deleter(data->s_a_head);
	if (data->s_b_head)
		list_deleter(data->s_b_head);
	exit (0);
}

int	order_check(t_data *data)
{
	int		i;
	t_value	*current;

	i = 0;
	current = data->s_a_head;
	while (current->next)
	{
		if (current->val >= current->next->val)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

void	get_shorts(t_data *data, int sl1, int sl2)
{
	t_value	*cur;

	data->short_head= 0;
	cur = data->s_a_head;
	while (cur)
	{
		if (cur->slice == sl1 || cur->slice == sl2)
			break ;
		data->short_head++;
		cur = cur->next;
	}
	data->short_tail = 1;
	cur = data->s_a_tail;
	while (cur)
	{
		if (cur->slice == sl1 || cur->slice == sl2)
			break ;
		data->short_tail++;
		cur = cur->prev;
	}
}

void	rotate_to_short(t_data *data)
{
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
}
