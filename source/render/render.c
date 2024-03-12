/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:24 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/12 11:01:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int init_data_img(t_context *context)
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

int init_rendering(t_context *context)
{
    if (init_mlx_session(context) == FAILURE)
        return (FAILURE);
    if (open_window(context) == FAILURE)
        return (FAILURE);
    if (init_data_img(context) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}