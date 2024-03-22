/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:24 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:05:28 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int create_image(t_context *context)
{
    void *image;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    
    image = mlx_new_image(context->mlx_session->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (image == NULL)
        return (print_error("Unable to create image"));
    addr = mlx_get_data_addr(image, &bits_per_pixel, &line_length, &endian);
    if (addr == NULL)
        return (print_error("Unable to get image address"));
    context->mlx_session->image = (t_img *)malloc(sizeof(t_img));
    if (context->mlx_session->image == NULL)
        return (print_error("Unable to allocate memory for data_img"));
    context->mlx_session->image->mlx_img = image;
    context->mlx_session->image->addr = addr;
    context->mlx_session->image->bits_per_pixel = bits_per_pixel;
    context->mlx_session->image->line_length = line_length;
    context->mlx_session->image->endian = endian;
    return (SUCCESS);
}

void	set_pixel_color(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	render_image(t_context *context)
{
	t_dir_pixel	pixel;
	int			i;
	int			j;
	int			color;
	
	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i < WINDOW_WIDTH)
		{
			pixel = context->dir_pixel[j][i];
			intersection(*context->camera->position, &pixel, context->element_list);
			pixel.color_ambient = calculate_ambient_light_color(pixel.col_obj, color_to_int(*context->ambient_light->color), context->ambient_light->intensity);
			color = pixel.color_ambient;
			pixel.diffuse_light = search_diffuse_light(pixel, context);
			color = sum_light(color, pixel.diffuse_light);
			set_pixel_color(context->mlx_session->image, i, j, color);
            free(pixel.intersection);
		}
        free(context->dir_pixel[j]);
	}
    free(context->dir_pixel);
}

int run_rendering(t_context *context)
{
    printf("Initializing rendering\n");
    if (init_mlx_session(context) == FAILURE)
        return (FAILURE);
    if (create_image(context) == FAILURE)
        return (FAILURE);
    printf("Rendering initialized successfully\n");
    printf("Generating image\n");
	init_camera_basis(context->base_cam, context);
	init_projection(context->base_cam, context->camera, context->dist_cam, context);
    render_image(context);
    printf("Image generation finished\n");
    return (SUCCESS);
}