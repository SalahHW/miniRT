/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:37:06 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/12 12:52:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void intersection(t_vector camera_position, t_dir_pixel *pixel, t_element_list *list)
{
    t_element *current_element;

    current_element = list->head;
    while (current_element)
    {
		if (current_element->identifier == plane)
            intersection_plan(camera_position, pixel, current_element->u_element.plane);
		current_element = current_element->next;
    }
	current_element = list->head;
	while (current_element)
    {
		if (current_element->identifier == sphere)
            intersection_sphere(camera_position, pixel, current_element->u_element.sphere);
		current_element = current_element->next;
    }
	current_element = list->head;
	while (current_element)
    {
		if (current_element->identifier == cylinder)
			intersection_cylinder(camera_position, pixel, current_element->u_element.cylinder);
		current_element = current_element->next;
    }
}

void	run_minirt(t_context *context)
{
	t_dir_pixel	pixel;
	int			i;
	int			j;
	int			color;
	int			color2;
	
	color = 0;
	j = -1;
	create_base_cam(context->base_cam, context);
	init_vec(context->base_cam, context->camera, context->dist_cam, context);
	while (++j < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
		{
			pixel = context->dir_pixel[j][i];
			intersection(*context->camera->position, &pixel, context->element_list);
			pixel.color_ambient = calculate_ambient_light_color(pixel.col_obj,
					color_to_int(*context->ambient_light->color), context->ambient_light->intensity);
			color = pixel.color_ambient;
			pixel.diffuse_light = search_diffuse_light(pixel, context);
			color2 = pixel.diffuse_light;
			color = sum_light(color, color2);
			my_mlx_pixel_put(context->mlx_session->image, i, j, color);
		}
	}
}
