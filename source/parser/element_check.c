/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:41 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:26:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	check_element(t_element *element)
{
	if (element->identifier == ambient_light)
		return (check_ambient_light(element));
	else if (element->identifier == camera)
	    return (check_camera(element));
	else if (element->identifier == light)
	    return (check_light(element));
	else if (element->identifier == sphere)
	    return (check_sphere(element));
	else if (element->identifier == plane)
	    return (check_plane(element));
	else if (element->identifier == cylinder)
	    return (check_cylinder(element));
	return (SUCCESS);
}

int	check_element_list(t_element_list *element_list)
{
	t_element *element;

	element = element_list->head;
	while (element)
	{
		if (check_element(element) == FAILURE)
            return (FAILURE);
		element = element->next;
	}
    return (SUCCESS);
}