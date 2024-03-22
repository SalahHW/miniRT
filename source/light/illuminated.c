/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illuminated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:49:45 by flmartin          #+#    #+#             */
/*   Updated: 2024/03/22 18:17:02 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	not_illum_sphere(t_vector pos, t_vector dir, t_context *minirt,
		double distance)
{
	t_element	*current_element;

	current_element = minirt->element_list->head;
	while (current_element)
	{
		if (current_element->identifier == sphere)
		{
			if (intersection_sphere_bis(pos, dir,
					&current_element->u_element.sphere, distance))
				return (1);
		}
		current_element = current_element->next;
	}
	return (0);
}

static int	not_illum_plan(t_vector pos, t_vector dir, t_context *minirt,
		double distance)
{
	t_element	*current_element;

	current_element = minirt->element_list->head;
	while (current_element)
	{
		if (current_element->identifier == plane)
		{
			if (intersection_plan_bis(pos, dir,
					&current_element->u_element.plane, distance))
				return (1);
		}
		current_element = current_element->next;
	}
	return (0);
}

static int	not_illum_cyl(t_vector pos, t_vector dir, t_context *minirt,
		double distance)
{
	t_element	*current_element;

	current_element = minirt->element_list->head;
	while (current_element)
	{
		if (current_element->identifier == cylinder)
		{
			if (intersection_cyls_bis(pos, dir,
					&current_element->u_element.cylinder, distance))
				return (1);
		}
		current_element = current_element->next;
	}
	return (0);
}

int	not_illum(t_vector pos, t_vector dir, t_context *minirt, double distance)
{
	if (not_illum_sphere(pos, dir, minirt, distance))
		return (1);
	if (not_illum_plan(pos, dir, minirt, distance))
		return (1);
	if (not_illum_cyl(pos, dir, minirt, distance))
		return (1);
	return (0);
}
