/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   session.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:34:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:34:32 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	init_mlx_session(t_context *context)
{
	t_mlx_session	*mlx_session;

	mlx_session = (t_mlx_session *)malloc(sizeof(t_mlx_session));
	if (!mlx_session)
		return (print_error("Failed to allocate memory for mlx"));
	context->mlx_session = mlx_session;
	context->mlx_session->mlx = mlx_init();
	if (!context->mlx_session->mlx)
	{
		free(context->mlx_session);
		return (print_error("Failed to initialize mlx"));
	}
	return (SUCCESS);
}

int	clear_mlx_session(t_context *context)
{
	if (context->mlx_session->mlx)
		free(context->mlx_session->mlx);
	if (context->mlx_session->image)
		free(context->mlx_session->image);
	if (context->mlx_session)
		free(context->mlx_session);
	return (SUCCESS);
}
