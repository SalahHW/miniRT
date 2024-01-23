/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 06:37:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/23 02:09:32 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_element(char **data, t_element *element)
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
