/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fda-estr <fda-estr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:36:11 by fda-estr          #+#    #+#             */
/*   Updated: 2023/11/05 10:56:37 by fda-estr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	move_ss_c(t_data *data)
{
	move_sa_c(data);
	move_sb_c(data);
}
void	move_rr_c(t_data *data)
{
	move_ra_c(data);
	move_rb_c(data);
}
void	move_rrr_c(t_data *data)
{
	move_rra_c(data);
	move_rrb_c(data);
}
