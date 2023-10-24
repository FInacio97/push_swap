/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:58:50 by fda-estr          #+#    #+#             */
/*   Updated: 2023/10/23 17:22:32 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_value
{
	struct s_value *next;
	struct s_value *prev;	
	int 			val;
	int				index;
	int				slice;
}				t_value;

typedef struct s_data
{
	t_value	*s_a_head;
	t_value	*s_b_head;
	t_value	*s_a_tail;
	t_value	*s_b_tail;
	int		s_a_nbr;
	int		s_b_nbr;
	int		short_head;
	int		short_tail;
	int		rate;
}				t_data;

/*PARSING*/
int		min_finder(t_data *data);
void	indexer(t_data *data, int low_n, int i);
void	doubles_checker(t_data *data);
void	ft_parsing(char **av, t_data *data);

/*MOVES A*/
void	move_sa(t_data *data);
void	move_pa(t_data *data);
void	move_ra(t_data *data);
void	move_rra(t_data * data);

/*MOVES B*/
void	move_sb(t_data *data);
void	move_pb(t_data *data);
void	move_rb(t_data *data);
void	move_rrb(t_data * data);

/*UTILS*/
t_value	*new_list(int val);
void	list_deleter(t_value *node);
void	add_list(t_data *data, int val);
void	print_list(t_value *head);
void	pars_checker(t_data *data, char *str);
void	ft_print_both_lists(t_data *data);
void	to_exit(t_data *data, char *s);

/*UTILS 2*/
int		order_check(t_data *data);
int		get_index(t_value *node, int ind);
void	rater(t_data *data);
void	get_shorts(t_data *data, int sl1, int sl2);

/*SORT 2*/
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4(t_data *data);

#endif