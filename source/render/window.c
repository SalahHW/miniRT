/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/29 16:02:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int open_window(t_context *context)
{
    context->mlx_session->win = mlx_new_window(context->mlx_session->mlx,  WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
    return (SUCCESS);
}

int close_window(t_context *context)
{
    mlx_destroy_window(context->mlx_session->mlx, context->mlx_session->win);
    mlx_destroy_display(context->mlx_session->mlx);
    if (context->mlx_session->mlx)
        free(context->mlx_session->mlx);
    if (context->mlx_session)
        free(context->mlx_session);
    quit_program(context);
}