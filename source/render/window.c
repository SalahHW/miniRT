/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:10:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:37:06 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void	run_hooks(t_context *context)
{
	mlx_hook(context->mlx_session->win, 17, 1L << 3, close_window, context);
	mlx_key_hook(context->mlx_session->win, deal_key, context);
	mlx_loop(context->mlx_session->mlx);
}

static int	open_window(t_context *context)
{
	context->mlx_session->win = NULL;
	context->mlx_session->win = mlx_new_window(context->mlx_session->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (context->mlx_session->win == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static int	display_image(t_context *context)
{
	int	image;

	image = mlx_put_image_to_window(context->mlx_session->mlx,
			context->mlx_session->win, context->mlx_session->image->mlx_img, 0,
			0);
	if (image == 0)
	{
		close_window(context);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	run_window(t_context *context)
{
	printf("Opening window\n");
	if (open_window(context) == FAILURE)
		return (print_error("Error while opening window"));
	if (display_image(context) == FAILURE)
		return (print_error("Error while displaying image"));
	printf("Window opened successfully\n");
	printf("Press ESC or close the window to exit\n");
	run_hooks(context);
	return (SUCCESS);
}

int	close_window(t_context *context)
{
	mlx_destroy_image(context->mlx_session->mlx,
		context->mlx_session->image->mlx_img);
	mlx_destroy_window(context->mlx_session->mlx, context->mlx_session->win);
	mlx_destroy_display(context->mlx_session->mlx);
	clear_mlx_session(context);
	quit_program(context);
	return (SUCCESS);
}
