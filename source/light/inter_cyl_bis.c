/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cyl_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:56:42 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 17:10:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	intersection_cyls_bis(t_vector pos, t_vector dir, t_cylinder *cyl, double distance)
{
	if (intersection_cyl_bis(pos, dir, cyl, distance))
		return (1);
	if (intersection_cyl2_bis(pos, dir, cyl, distance))
		return (1);
	if (intersection_cyl3_bis(pos, dir, cyl, distance))
		return (1);
	return (0);
}

int	intersection_cyl_bis(t_vector pos, t_vector dir, t_cylinder *cyl, double distance)
{
	double	a;
	double	b;
	double	c;
	double	dist;

	a = get_a_cyl(dir, *cyl);
	if (a == 0)
		return (0);
	b = get_b_cyl(dir, *cyl, diff_vec(pos, *cyl->position));
	c = get_c_cyl(*cyl, diff_vec(pos, *cyl->position));
	dist = sol_quadratic_equation(a, b, c);
	if (dist <= distance && dist > 0.000001)
	{
		if (not_in_range(sum_vec(pos, prod_nb_vec(dist, dir)), *cyl))
			return (0);
		return (1);
	}
	return (0);
}

int	intersection_cyl2_bis(t_vector pos, t_vector dir, t_cylinder *cyl, double distance)
{
	t_vector	h;
	t_vector	intersection;
	double	dist;

	if (prod_scal(*cyl->direction, dir) == 0)
		return (0);
	h = prod_nb_vec(cyl->height / 2, *cyl->direction);
	h = sum_vec(*cyl->position, h);
	dist = prod_scal(*cyl->direction, diff_vec(h, pos));
	dist = dist / prod_scal(*cyl->direction, dir);
	if (dist <= distance && dist > 0.000001)
	{
		intersection = sum_vec(pos, prod_nb_vec(dist, dir));
		if (norm_vec(diff_vec(intersection, h)) <= cyl->diameter)
			return (1);
	}
	return (0);
}

int	intersection_cyl3_bis(t_vector pos, t_vector dir, t_cylinder *cyl, double distance)
{
	t_vector	h;
	t_vector	intersection;
	double	dist;

	if (prod_scal(*cyl->direction, dir) == 0)
		return (0);
	h = prod_nb_vec(-cyl->height / 2, *cyl->direction);
	h = sum_vec(*cyl->position, h);
	dist = prod_scal(*cyl->direction, diff_vec(h, pos));
	dist = dist / prod_scal(*cyl->direction, dir);
	if (dist <= distance && dist > 0.000001)
	{
		intersection = sum_vec(pos, prod_nb_vec(dist, dir));
		if (norm_vec(diff_vec(intersection, h)) <= cyl->diameter)
			return (1);
	}
	return (0);
}
