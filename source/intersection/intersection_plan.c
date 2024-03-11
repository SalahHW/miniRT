/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:50:27 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 17:14:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	intersection_plan(t_vector camera_position, t_dir_pixel *dir, t_plane plane)
{
	double		dist;
	t_vector	tmp;

	if (prod_scal(*plane.direction, dir->dir_pixel) == 0)
		return ;
	dist = (prod_scal(*plane.direction, diff_vec(*plane.position, camera_position))
			/ prod_scal(*plane.direction, dir->dir_pixel));
	if (dist <= 0)
		return ;
	if (dir->dist == 0 || dist <= dir->dist)
	{
		dir->did_it_touch = 1;
		dir->dist = dist;
		dir->col_obj = color_to_int(*plane.color);
		tmp = prod_nb_vec(dist, dir->dir_pixel);
		*dir->intersection = sum_vec(camera_position, tmp);
		dir->n = get_normal_plan(*plane.direction, diff_vec(*dir->intersection, camera_position));
	}
	return ;
}