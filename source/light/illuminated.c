/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:49:45 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/11 17:04:11 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	not_illum(t_vector pos, t_vector dir, t_context *minirt, double distance)
{
	t_element	*current_element;

	current_element = minirt->element_list->head;
	while (current_element)
	{
		if (current_element->identifier == sphere)
		{
			if (intersection_sphere_bis(pos, dir, &current_element->u_element.sphere, distance))
				return (1);
		}
		else if (current_element->identifier == plane)
		{
			if (intersection_plan_bis(pos, dir, &current_element->u_element.plane, distance))
				return (1);
		}
		else if (current_element->identifier == cylinder)
		{
			if (intersection_cyl_bis(pos, dir, &current_element->u_element.cylinder, distance))
				return (1);
		}
		current_element = current_element->next;
	}
	return (0);
}
