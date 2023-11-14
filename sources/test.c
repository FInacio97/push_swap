/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:16:57 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 21:19:21 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_value *head)
{
	int	i;

	i = 0;
	ft_printf("List:	");
	while (head)
	{
		ft_printf("%d|%d	", head->val, head->index);
		head = head->next;
		i++;
	}
	ft_printf("\n");
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

void	print_moves_reverse(t_moves *head)
{
	t_moves	*current;

	current = head;
	printf("\nList Reversed\n");
	if (current->next == NULL)
		ft_printf("NULL\n");
	while (current)
	{
		ft_printf("%s", current->move);
		current = current->prev;
	}
	if (current == NULL)
		ft_printf("NULL\n");
}
