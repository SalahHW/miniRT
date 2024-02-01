/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:14:10 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 04:49:21 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_element	*init_element(void)
{
	t_element	*new_element;

	new_element = (t_element *)malloc(sizeof(t_element));
	if (!new_element)
		return (NULL);
	new_element->identifier = unknown;
	new_element->initialized = 0;
	new_element->next = NULL;
	return (new_element);
}

void clear_element(t_element *element)
{
	if (element->identifier == ambient_light)
		clear_ambient_light(element);
	else if (element->identifier == camera)
		clear_camera(element);
	else if (element->identifier == light)
		clear_light(element);
	else if (element->identifier == sphere)
		clear_sphere(element);
	else if (element->identifier == plane)
		clear_plane(element);
	else if (element->identifier == cylinder)
		clear_cylinder(element);
	free(element);
}