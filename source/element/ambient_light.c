/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:29:33 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/02 12:41:29 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_ambient_light(char **data, t_element *element)
{
	t_ambient_light ambient_light;

	if (split_length(data) != 3)
		return ;
	ambient_light.intensity = extract_decimal(data[1]);
	ambient_light.color = extract_color(data[2]);
	element->u_element.ambient_light = ambient_light;
	element->initialized = 1;
}

void clear_ambient_light(t_element *element)
{
	if (!element->initialized)
		return ;
	clear_decimal(element->u_element.ambient_light.intensity);
	clear_color(element->u_element.ambient_light.color);
}