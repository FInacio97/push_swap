/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:14:16 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 21:35:35 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_finder(t_data *data)
{
	t_value	*current;
	t_value	*min;

	min = data->s_a_head;
	current = min->next;
	while (current)
	{
		if (min->val > current->val)
			min = current;
		current = current->next;
	}
	min->index = 0;
	min->slice = min->index / data->rate;
	return (min->val);
}

void	indexer(t_data *data, int low_n, int i)
{
	t_value	*current;
	t_value	*next_ind;

	if (i == data->s_a_nbr)
		return ;
	next_ind = data->s_a_head;
	while (next_ind->index >= 0)
		next_ind = next_ind->next;
	current = next_ind->next;
	while (current)
	{
		if (current->index >= 0)
		{
			current = current->next;
			continue ;
		}
		if (current->val < next_ind->val)
			next_ind = current;
		current = current->next;
	}
	if (low_n < next_ind->val)
		next_ind->index = i;
	next_ind->slice = next_ind->index / data->rate;
	indexer(data, next_ind->val, i + 1);
}

void	doubles_checker(t_data *data)
{
	t_value	*current;

	current = data->s_a_head;
	while (current)
	{
		if (current->index < 0)
			to_exit(data, "||ERROR||\nCannot contain doubles!\n");
		current = current->next;
	}
}

void	slice_remover(t_data *data)
{
	t_value	*current;

	current = data->s_a_head;
	while (current)
	{
		if (current->index > data->s_a_nbr - 6)
			current->slice = -1;
		current = current->next;
	}
}

void	ft_parsing(char **av, t_data *data)
{
	int	i;

	i = 0;
	data->s_a_nbr = 0;
	data->s_b_nbr = 0;
	while (av[++i])
	{
		pars_checker(data, av[i]);
		add_list(data, ft_atoi(av[i]));
	}
	rater(data);
	indexer(data, min_finder(data), 1);
	slice_remover(data);
	doubles_checker(data);
}

/*
1 1 2 2 3 3
2 3 1 3 1 2
3 2 3 1 2 1
*/