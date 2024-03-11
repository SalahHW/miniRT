/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:24 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/11 13:36:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int init_data_img(t_context *context)
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    
    img = mlx_new_image(context->mlx_session->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (img == NULL)
        return (print_error("Unable to create image"));
    addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
    if (addr == NULL)
        return (print_error("Unable to get image address"));
    context->mlx_session->img = (t_data *)malloc(sizeof(t_data));
    if (context->mlx_session->img == NULL)
        return (print_error("Unable to allocate memory for data_img"));
    context->mlx_session->img->img = img;
    context->mlx_session->img->addr = addr;
    context->mlx_session->img->bits_per_pixel = bits_per_pixel;
    context->mlx_session->img->line_length = line_length;
    context->mlx_session->img->endian = endian;
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