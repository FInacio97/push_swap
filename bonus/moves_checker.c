/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:54:41 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/05 11:04:24 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	move_sort(t_data *data, char *move)
{
	if (ft_strncmp(move, "sa\n", 5) == 0)
		move_sa_c(data);
	else if (ft_strncmp(move, "pa\n", 5) == 0)
		move_pa_c(data);
	else if (ft_strncmp(move, "ra\n", 5) == 0)
		move_ra_c(data);
	else if (ft_strncmp(move, "rra\n", 5) == 0)
		move_rra_c(data);
	else if (ft_strncmp(move, "sb\n", 5) == 0)
		move_sb_c(data);
	else if (ft_strncmp(move, "pb\n", 5) == 0)
		move_pb_c(data);
	else if (ft_strncmp(move, "rb\n", 5) == 0)
		move_rb_c(data);
	else if (ft_strncmp(move, "rrb\n", 5) == 0)
		move_rrb_c(data);
	else if (ft_strncmp(move, "ss\n", 5) == 0)
		move_ss_c(data);
	else if (ft_strncmp(move, "rr\n", 5) == 0)
		move_ss_c(data);
	else if (ft_strncmp(move, "rrr\n", 5) == 0)
		move_ss_c(data);
	else
	{
		ft_printf("%s\n", move);
		to_exit_c(data, "||ERROR||\nInvalid move!");
	}
}

void	moves_checker(t_data *data)
{
	char	*move;
	int		move_nbr;

	move_nbr = 0;
	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		else
			move_sort(data, move);
		free (move);
		move_nbr++;
	}
	ft_printf("Number of moves: %d\n", move_nbr);
}
