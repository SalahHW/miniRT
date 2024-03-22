/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:50:32 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/22 18:26:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	intersection_sphere(t_vector cam, t_dir_pixel *dir, t_sphere sphere)
{
	double	a;
	double	b;
	double	c;
	double	dist;

	a = 1;
	b = prod_scal(cam, dir->dir_pixel);
	b -= prod_scal(dir->dir_pixel, *sphere.position);
	b *= 2;
	c = prod_scal(cam, cam);
	c -= 2 * prod_scal(cam, *sphere.position);
	c += prod_scal(*sphere.position, *sphere.position);
	c -= (sphere.diameter / 2) * (sphere.diameter / 2);
	dist = sol_quadratic_equation(a, b, c);
	if (dist <= dir->dist && dist > 0)
	{
		dir->did_it_touch = 1;
		dir->dist = dist;
		dir->col_obj = color_to_int(*sphere.color);
		*dir->intersection = prod_nb_vec(dist, dir->dir_pixel);
		*dir->intersection = sum_vec(cam, *dir->intersection);
		dir->n = get_normal_sphere(*dir->intersection, *sphere.position);
	}
	return ;
}
