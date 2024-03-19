/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmartin <flmartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:51:24 by flmartin          #+#    #+#             */
/*   Updated: 2023/12/15 16:14:02 by flmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	init_camera_basis(t_base *base_cam, t_context *minirt)
{
	t_vector	j;

	j.x = 0;
	j.y = 1;
	j.z = 0;
	base_cam->w = *minirt->camera->orientation;
	base_cam->u = prod_vec(j, base_cam->w);
	base_cam->u = prod_nb_vec(1 / norm_vec(base_cam->u), base_cam->u);
	base_cam->v = prod_vec(base_cam->w, base_cam->u);
	base_cam->v = prod_nb_vec(1 / norm_vec(base_cam->v), base_cam->v);
	base_cam->pos = *minirt->camera->position;
	minirt->dist_cam = 1;
	return ;
}

int	use_dir_origin(t_vector dir_origin, double step_x, double step_y,
	t_context *minirt)
{
	t_vector	dir;
	int		x;
	int		y;

	y = -1;
	if (allocate_dir_pixel_array(minirt) == -1)
		return (-1);
	while (++y < WINDOW_HEIGHT)
	{
		if (allocate_dir_pixel_row(minirt, y) == -1)
			return (-1);
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			if (allocate_intersection(minirt, y, x) == -1)
				return (-1);
			initialize_and_update_pixel(&(minirt->dir_pixel[y][x]));
			dir = dir_origin;
			dir = sum_vec(dir, prod_nb_vec(x * step_x, minirt->base_cam->u));
			dir = sum_vec(dir, prod_nb_vec(y * step_y, minirt->base_cam->v));
			dir = prod_nb_vec(1 / norm_vec(dir), dir);
			minirt->dir_pixel[y][x].dir_pixel = dir;
		}
	}
	return (0);
}

int	init_projection(t_base *base_cam, t_camera *cam, double dist_cam,
	t_context *minirt)
{
	t_vector	dir_origin;
	double	step_x;
	double	step_y;
	double	l;
	double	h;

	l = 2 * dist_cam * tan((cam->fov / 2) * (M_PI / 180));
	h = ((double)WINDOW_HEIGHT / (double)WINDOW_WIDTH) * l;
	dir_origin = *cam->orientation;
	dir_origin = sum_vec(dir_origin, prod_nb_vec(-l / 2, base_cam->u));
	dir_origin = sum_vec(dir_origin, prod_nb_vec(-h / 2, base_cam->v));
	step_x = l / (WINDOW_WIDTH - 1);
	step_y = h / (WINDOW_HEIGHT - 1);
	if (use_dir_origin(dir_origin, step_x, step_y, minirt))
		return (-1);
	return (0);
}
