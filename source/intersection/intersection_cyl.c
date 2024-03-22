/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cyl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:50:20 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/12 15:44:04 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void	intersection_cyl(t_vector cam, t_dir_pixel *dir, t_cylinder cyl)
{
	double	a;
	double	b;
	double	c;
	double	dist;

	a = get_a_cyl(dir->dir_pixel, cyl);
	if (a == 0)
		return ;
	b = get_b_cyl(dir->dir_pixel, cyl, diff_vec(cam, *cyl.position));
	c = get_c_cyl(cyl, diff_vec(cam, *cyl.position));
	dist = sol_quadratic_equation(a, b, c);
	if ((dir->dist == 0 || dist <= dir->dist) && dist > 0)
	{
		if (not_in_range(sum_vec(cam, prod_nb_vec(dist, dir->dir_pixel)), cyl))
			return ;
		dir->did_it_touch = 1;
		dir->dist = dist;
		dir->col_obj = color_to_int(*cyl.color);
		*dir->intersection = sum_vec(cam, prod_nb_vec(dist, dir->dir_pixel));
		dir->n = get_normal_cyl(*dir->intersection, *cyl.direction,
				*cyl.position);
	}
	return ;
}

static void	intersection_cyl2(t_vector cam, t_dir_pixel *dir, t_cylinder cyl)
{
	t_vector	h;
	t_vector	intersection;
	double		dist;

	if (prod_scal(*cyl.direction, dir->dir_pixel) == 0)
		return ;
	h = prod_nb_vec(cyl.height / 2, *cyl.direction);
	h = sum_vec(*cyl.position, h);
	dist = prod_scal(*cyl.direction, diff_vec(h, cam));
	dist = dist / prod_scal(*cyl.direction, dir->dir_pixel);
	if (dist <= 0)
		return ;
	intersection = sum_vec(cam, prod_nb_vec(dist, dir->dir_pixel));
	if (dist <= dir->dist && (norm_vec(diff_vec(intersection,
					h)) <= (cyl.diameter / 2)))
	{
		dir->did_it_touch = 1;
		dir->dist = dist;
		dir->col_obj = color_to_int(*cyl.color);
		*dir->intersection = intersection;
		dir->n = get_normal_plan(*cyl.direction, diff_vec(*dir->intersection,
					cam));
	}
	return ;
}

static void	intersection_cyl3(t_vector cam, t_dir_pixel *dir, t_cylinder cyl)
{
	t_vector	h;
	t_vector	intersection;
	double		dist;

	if (prod_scal(*cyl.direction, dir->dir_pixel) == 0)
		return ;
	h = prod_nb_vec(-cyl.height / 2, *cyl.direction);
	h = sum_vec(*cyl.position, h);
	dist = prod_scal(*cyl.direction, diff_vec(h, cam));
	dist = dist / prod_scal(*cyl.direction, dir->dir_pixel);
	if (dist <= 0)
		return ;
	intersection = sum_vec(cam, prod_nb_vec(dist, dir->dir_pixel));
	if (dist <= dir->dist && (norm_vec(diff_vec(intersection,
					h)) <= (cyl.diameter / 2)))
	{
		dir->did_it_touch = 1;
		dir->dist = dist;
		dir->col_obj = color_to_int(*cyl.color);
		*dir->intersection = intersection;
		dir->n = get_normal_plan(*cyl.direction, diff_vec(*dir->intersection,
					cam));
	}
	return ;
}

void	intersection_cylinder(t_vector cam, t_dir_pixel *dir, t_cylinder cyl)
{
	intersection_cyl(cam, dir, cyl);
	intersection_cyl2(cam, dir, cyl);
	intersection_cyl3(cam, dir, cyl);
}
