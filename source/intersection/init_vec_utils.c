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

void	initialize_and_update_pixel(t_dir_pixel *pixel)
{
	pixel->col_obj = 0;
	pixel->color_ambient = 0;
	pixel->diffuse_light = 0;
	pixel->dist = 0;
	pixel->did_it_touch = 0;
}

int	allocate_dir_pixel_array(t_context *minirt)
{
	minirt->dir_pixel = malloc(sizeof(t_dir_pixel *) * WINDOW_HEIGHT);
	if (!minirt->dir_pixel)
		return (-1);
	return (0);
}

int	allocate_dir_pixel_row(t_context *minirt, int y)
{
	minirt->dir_pixel[y] = malloc(sizeof(t_dir_pixel) * WINDOW_WIDTH);
	if (!minirt->dir_pixel[y])
		return (-1);
	return (0);
}

int	allocate_intersection(t_context *minirt, int y, int x)
{
	minirt->dir_pixel[y][x].intersection = ft_calloc(1, sizeof(t_vector));
	if (!minirt->dir_pixel[y][x].intersection)
		return (-1);
	return (0);
}
