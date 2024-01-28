/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 06:37:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 07:20:31 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_element(char **data, t_element *element)
{
	if (element->identifier == ambient_light)
		process_ambient_light(data, element);
	else if (element->identifier == camera)
		process_camera(data, element);
	else if (element->identifier == light)
		process_light(data, element);
	else if (element->identifier == sphere)
		process_sphere(data, element);
	else if (element->identifier == plane)
		process_plane(data, element);
	else if (element->identifier == cylinder)
		process_cylinder(data, element);
}
