/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plan_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:56:47 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 17:07:04 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	intersection_plan_bis(t_vector pos, t_vector dir, t_plane *plan, double distance)
{
	double	dist;

	if (prod_scal(*plan->direction, dir) == 0)
		return (0);
	dist = (prod_scal(*plan->direction, diff_vec(*plan->position, pos))
			/ prod_scal(*plan->direction, dir));
	if (dist <= distance && dist > 0.000001)
		return (1);
	return (0);
}
