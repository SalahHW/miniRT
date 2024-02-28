/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:29:33 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 04:46:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int check_ambient_light_values(char **data)
{
	if (split_length(data) != 3)
		return (print_error("Invalid syntax for ambient light"));
	if (!is_double_compatible(data[1]))
		return (print_error("Unable to get ambient light intensity"));
	if (is_color_compatible(data[2]) == FAILURE)
		return (print_error("Unable to get ambient light color"));
	return (SUCCESS);
}

int	process_ambient_light(char **data, t_element *element)
{
	t_ambient_light ambient_light;

	if (check_ambient_light_values(data) == FAILURE)
		return (FAILURE);
	ambient_light.intensity = string_to_double(data[1]);
	ambient_light.color = extract_color(data[2]);
	element->u_element.ambient_light = ambient_light;
	element->initialized = 1;
	return (SUCCESS);
}

void clear_ambient_light(t_element *element)
{
	if (!element->initialized)
		return ;
	clear_color(element->u_element.ambient_light.color);
}