/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 06:37:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/22 02:14:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_element(char *line, t_element *element)
{
	if (element->identifier == ambient_light)
		process_ambient_light(line, element);
	else if (element->identifier == camera)
		process_camera(line, element);
	else if (element->identifier == light)
		process_light(line, element);
	else if (element->identifier == sphere)
		process_sphere(line, element);
	else if (element->identifier == plane)
		process_plane(line, element);
	else if (element->identifier == cylinder)
		process_cylinder(line, element);
}
