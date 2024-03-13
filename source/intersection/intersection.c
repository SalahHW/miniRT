/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:37:06 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 10:55:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void intersection(t_vector camera_position, t_dir_pixel *pixel, t_element_list *list)
{
    t_element *current_element;

    current_element = list->head;
    while (current_element)
    {
		if (current_element->identifier == plane)
            intersection_plan(camera_position, pixel, current_element->u_element.plane);
		current_element = current_element->next;
    }
	current_element = list->head;
	while (current_element)
    {
		if (current_element->identifier == sphere)
            intersection_sphere(camera_position, pixel, current_element->u_element.sphere);
		current_element = current_element->next;
    }
	current_element = list->head;
	while (current_element)
    {
		if (current_element->identifier == cylinder)
			intersection_cylinder(camera_position, pixel, current_element->u_element.cylinder);
		current_element = current_element->next;
    }
}

