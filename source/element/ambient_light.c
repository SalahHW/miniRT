/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:29:33 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/09 19:40:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_ambient_light(char **data, t_element *element)
{
	t_ambient_light ambient_light;

	if (split_length(data) != 3)
		return(print_error("Invalid values for ambient light"));
	if (!is_double_compatible(data[1]))
		return (print_error("Unable to get ambient light intensity"));
	ambient_light.intensity = string_to_double(data[1]);
	ambient_light.color = extract_color(data[2]);
	if (!ambient_light.color)
		return (print_error("Unable to get ambient light color"));
	element->u_element.ambient_light = ambient_light;
	element->initialized = 1;
}

void clear_ambient_light(t_element *element)
{
	if (!element->initialized)
		return ;
	clear_color(element->u_element.ambient_light.color);
}