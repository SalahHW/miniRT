/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:29:06 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:13:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	check_list_counter(t_context *context)
{
	if (context->element_list->ambient_light_count < 1)
		return (print_error("No ambient light found"));
	if (context->element_list->ambient_light_count > 1)
		return (print_error("Too many ambient light found"));
	if (context->element_list->camera_count < 1)
		return (print_error("No camera found"));
	if (context->element_list->camera_count > 1)
		return (print_error("Too many camera found"));
	if (context->element_list->light_count < 1)
		return (print_error("No light found"));
	if (context->element_list->light_count > 1)
		return (print_error("Too many light found"));
	return (SUCCESS);
}
