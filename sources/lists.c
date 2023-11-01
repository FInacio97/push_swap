/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:31:07 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/01 12:05:16 by fda-estr         ###   ########.fr       */
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

		ft_printf("%d|%d	", head->val, head->slice_rel);
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

t_moves	*new_moves_list(char *move, char *list)
{
	t_moves	*node;

	node = (t_moves *)malloc(sizeof(t_moves));
	if (!node)
		return (NULL);
	node->move = ft_strdup(move);
	node->list = ft_strdup(list);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
