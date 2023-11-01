/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:58:50 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/01 12:43:04 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_value
{
	struct s_value	*next;
	struct s_value	*prev;	
	int				val;
	int				index;
	int				slice;
	int				slice_rel;
}				t_value;

typedef struct s_moves
{
	char			*move;
	char			*list;
	struct s_moves	*next;
	struct s_moves	*prev;
}				t_moves;

typedef struct s_data
{
	t_value	*s_a_head;
	t_value	*s_b_head;
	t_value	*s_a_tail;
	t_value	*s_b_tail;
	t_moves	*m_l_head;
	t_moves	*m_l_tail;
	int		s_a_nbr;
	int		s_b_nbr;
	int		short_head;
	int		short_tail;
	int		rate;
	int		moves_flag;
	int		moves_nbr;
}				t_data;

/*In the end, check for unused/useless/testing
  functions and delete them*/

/*PARSING*/
int		min_finder(t_data *data);
void	indexer(t_data *data, int low_n, int i);
void	doubles_checker(t_data *data);
void	ft_parsing(char **av, t_data *data);

/*MOVES A*/
void	move_sa(t_data *data);
void	move_pa(t_data *data);
void	move_ra(t_data *data);
void	move_rra(t_data *data);

/*MOVES B*/
void	move_sb(t_data *data);
void	move_pb(t_data *data);
void	move_rb(t_data *data);
void	move_rrb(t_data *data);

/*SORT 2*/
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4_helper(t_data *data, int *swap_check);
void	sort_4(t_data *data, int swap_check);
void	sort_5(t_data *data);

/*SORT 6*/
void	sort_to_9_helper(t_data *data);
void	sort_to_9(t_data *data);

/*UTILS*/
void	pars_checker(t_data *data, char *str);
void	to_exit(t_data *data, char *s);
int		order_check(t_data *data);
void	get_shorts(t_data *data, int sl1, int sl2);
void	rotate_to_short(t_data *data);

/*UTILS 2*/
int		get_index(t_value *node, int ind);
void	rater(t_data *data);
void	get_relative_shorts(t_data *data, int sl1, int sl2, int sl3);
void	optimizer_helper(t_data *data);
void	optimizer(t_data *data);

/*UTILS 3*/
void	relative_slicer_helper(t_value *node);
void	relative_slicer(t_data *data);
void	relative_slicer_s5(t_data *data);

/*LISTS*/
t_value	*new_list(int val);
void	list_deleter(t_value *node);
void	add_list(t_data *data, int val);
void	print_list(t_value *head);//	to delete
void	ft_print_both_lists(t_data *data);//	to delete
t_moves	*new_moves_list(char *move, char *list);

/*LISTS 2*/
void	move_to_list(t_data *data, char *move, char *list);
void	moves_node_deleter(t_moves *node);
void	list_moves_deleter(t_moves *node);
void	print_moves(t_moves *head);
void	print_moves_reverse(t_moves *head);// 	ONLY FOR TESTING

#endif