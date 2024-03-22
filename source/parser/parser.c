/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:43:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:14:19 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	run_parser(t_context *context)
{
	printf("Values checking started\n");
	if (check_list_counter(context) == FAILURE)
		return (FAILURE);
	if (check_element_list(context->element_list) == FAILURE)
		return (FAILURE);
	context->ambient_light = get_ambient_light(context->element_list);
	context->camera = get_camera(context->element_list);
	context->light = get_light(context->element_list);
	printf("Values checked successfully\n");
	return (SUCCESS);
}
