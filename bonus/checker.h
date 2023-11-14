/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:13:59 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/14 20:29:43 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../sources/push_swap.h"

/*PARSING*/
void	pars_checker_c(t_data *data, char *str);
void	double_checker_c(t_data *data);
void	ft_parsing_c(char **av, t_data *data);

/*MOVES_CHECKER*/
void	move_sort(t_data *data, char *move);
void	moves_checker(t_data *data);

/*MOVES A*/
void	move_sa_c(t_data *data);
void	move_pa_c(t_data *data);
void	move_ra_c(t_data *data);
void	move_rra_c(t_data *data);

/*MOVES B*/
void	move_sb_c(t_data *data);
void	move_pb_c(t_data *data);
void	move_rb_c(t_data *data);
void	move_rrb_c(t_data *data);

/*MOVES DOUBLE*/
void	move_ss_c(t_data *data);
void	move_rr_c(t_data *data);
void	move_rrr_c(t_data *data);

/*UTILS*/
void	order_check_c(t_data *data);
void	to_exit_c(t_data *data, char *s);

/*LISTS*/
t_value	*new_list_c(int val);
void	list_deleter_c(t_value *node);
void	add_list_c(t_data *data, int val);
void	print_list_c(t_value *head);
void	ft_print_both_lists_c(t_data *data);

#endif