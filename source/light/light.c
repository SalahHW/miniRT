/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:50:00 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 14:54:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	calculate_ambient_light_color(int obj_color, int ambient_color, double factor)
{
	int		color;
	double	tmp;

	color = 0;
	if (obj_color != 0)
	{
		tmp = (double)(ambient_color & 0x000000FF)
			*(double)(obj_color & 0x000000FF) *factor / 255.0;
		tmp = fmin(fmax(tmp, 0), 255);
		color += (int)tmp;
		tmp = (double)((ambient_color & 0x0000FF00) >> 8)
			*(double)((obj_color & 0x0000FF00) >> 8) *factor / 255.0;
		tmp = fmin(fmax(tmp, 0), 255);
		color += ((int)tmp) << 8;
		tmp = (double)((ambient_color & 0x00FF0000) >> 16)
			*(double)((obj_color & 0x00FF0000) >> 16) *factor / 255.0;
		tmp = fmin(fmax(tmp, 0), 255);
		color += ((int)tmp) << 16;
	}
	return (color);
}

int	search_diffuse_light(t_dir_pixel dir, t_context *minirt)
{
	t_element *current_element;
	int	res;

	res = 0;
	current_element = minirt->element_list->head;
	while (current_element)
	{
		if (current_element->identifier == light)
		{
			res = sum_light(res, diffuse_light(dir, current_element->u_element.light, minirt));
		}
		current_element = current_element->next;
	}
	return (res);
}

int	diffuse_light(t_dir_pixel dir, t_light light, t_context *minirt)
{
	t_vector	inter_to_light;
	double	cos_theta;
	double	factor_lux;
	double	distance;

	if (dir.did_it_touch == 0)
		return (0);
	inter_to_light = diff_vec(*light.position, *dir.intersection);
	distance = norm_vec(inter_to_light);
	inter_to_light = prod_nb_vec(1 / distance, inter_to_light);
	if (not_illum(*dir.intersection, inter_to_light, minirt, distance))
		return (0);
	cos_theta = prod_scal(dir.n, inter_to_light);
	if (cos_theta <= 0)
		return (0);
	factor_lux = light.brightness * cos_theta;
	return (color_diffuse_light(color_to_int(*light.color), dir.col_obj, factor_lux));
}

int	color_diffuse_light(int light_color, int col_obj, double factor_lux)
{
	int		color;
	double	tmp;

	color = 0;
	if (col_obj != 0)
	{
		tmp = (double)(light_color & 0x000000FF)
			*(double)(col_obj & 0x000000FF) *factor_lux / 255.0;
		tmp = fmin(fmax(tmp, 0), 255);
		color += (int)tmp;
		tmp = (double)((light_color & 0x0000FF00) >> 8)
			*(double)((col_obj & 0x0000FF00) >> 8) *factor_lux / 255.0;
		tmp = fmin(fmax(tmp, 0), 255);
		color += ((int)tmp) << 8;
		tmp = (double)((light_color & 0x00FF0000) >> 16)
			*(double)((col_obj & 0x00FF0000) >> 16) *factor_lux / 255.0;
		tmp = fmin(fmax(tmp, 0), 255);
		color += ((int)tmp) << 16;
	}
	return (color);
}

int	sum_light(int color_a, int color_b)
{
	int	color;
	int	tmp;

	color = 0;
	tmp = (color_a & 0x000000FF) + (color_b & 0x000000FF);
	if (tmp > 255)
		color = 0x000000FF;
	else
		color += tmp;
	tmp = (((color_a & 0x0000FF00) >> 8) + ((color_b & 0x0000FF00) >> 8));
	if (tmp > 255)
		color += 0x0000FF00;
	else
		color += (tmp << 8);
	tmp = (((color_a & 0x00FF0000) >> 16) + ((color_b & 0x00FF0000) >> 16));
	if (tmp > 255)
		color += 0x00FF0000;
	else
		color += (tmp << 16);
	return (color);
}
