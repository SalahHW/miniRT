/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:24 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/29 15:10:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int run_render(t_context *context)
{
    if (init_mlx_session(context) == FAILURE)
        return (FAILURE);
    if (open_window(context) == FAILURE)
        return (FAILURE);
    mlx_hook(context->mlx_session->win, 17, 1L << 3, close_window, context);
    mlx_key_hook(context->mlx_session->win, deal_key, context);
    mlx_loop(context->mlx_session->mlx);
    return (SUCCESS);
}