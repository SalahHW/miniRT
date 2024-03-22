/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:51:00 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/22 18:16:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	get_normal_plan(t_vector n, t_vector cam_to_inter)
{
	cam_to_inter = prod_nb_vec(1 / norm_vec(cam_to_inter), cam_to_inter);
	if (prod_scal(cam_to_inter, n) > 0)
		return (prod_nb_vec(-1, n));
	return (n);
}
