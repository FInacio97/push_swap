/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:24:38 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/23 12:34:05 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	*new_list(int val)
{
	t_value	*node;

	node = (t_value *)malloc(sizeof(t_value));
	if (!node)
		return (NULL);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	node->index = -1;
	return (node);
}

void	list_deleter(t_value *node)
{
	t_value	*temp;

	while (node)
	{
		temp = node->next;
		free (node);
		node = temp;
	}
}

void	add_list(t_data *data, int val)
{
	t_value	*temp;

	temp = data->s_a_tail;
	data->s_a_tail = new_list(val);
	if (data->s_a_nbr == 0)
	{
		data->s_a_head = data->s_a_tail;
		data->s_a_nbr++;
		return ;
	}
	data->s_a_tail->prev = temp;
	temp->next = data->s_a_tail;
	data->s_a_nbr++;
}

void	print_list(t_value *head)
{
	int	i;

	i = 0;
	ft_printf("List:	");
	while (head)
	{
		// if (head->prev == NULL && head->next != NULL)
		// 	ft_printf("(NULL|%d|%d)	", head->val, head->next->val);
		// else if (head->prev != NULL && head->next == NULL)
		// 	ft_printf("(%d|%d|NULL)	", head->prev->val, head->val);
		// else if (head->prev == NULL && head->next == NULL)
		// 	ft_printf("(NULL|%d|NULL)	", head->val);
		// else
		// 	ft_printf("(%d|%d|%d)	", head->prev->val, head->val, head->next->val);


		// ft_printf("(%d|%d)	", head->val, head->index);

		ft_printf("%d|%d	", head->val, head->slice);
		head = head->next;
		i++;
	}
	ft_printf("\n");
}

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

void	ft_print_both_lists(t_data *data)
{
	if (data->s_a_nbr > 0)
		print_list(data->s_a_head);
	else
		ft_printf("Nothing in stack A...\n");
	if (data->s_b_nbr > 0)
		print_list(data->s_b_head);
	else
		ft_printf("Nothing in stack B...\n");
	ft_printf("Stack A values: %d\n", data->s_a_nbr);
	ft_printf("Stack B values: %d\n\n", data->s_b_nbr);
	if (data->s_a_tail == NULL || !data->s_a_tail)
		ft_printf("No tail on Stack A!\n");
	if (data->s_b_tail == NULL || !data->s_b_tail)
		ft_printf("No tail on Stack B!\n");
}

void	to_exit(t_data *data, char *s)
{
	ft_printf("%s\n", s);
	if (data->s_a_head)
		list_deleter(data->s_a_head);
	if (data->s_b_head)
		list_deleter(data->s_b_head);
	exit (0);
}
