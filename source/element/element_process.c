/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 06:37:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:37:31 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_element(char **data, t_element *element)
{
	if (element->identifier == ambient_light)
		return (process_ambient_light(data, element));
	else if (element->identifier == camera)
		return (process_camera(data, element));
	else if (element->identifier == light)
		return (process_light(data, element));
	else if (element->identifier == sphere)
		return (process_sphere(data, element));
	else if (element->identifier == plane)
		return (process_plane(data, element));
	else if (element->identifier == cylinder)
		return (process_cylinder(data, element));
	return (SUCCESS);
}
