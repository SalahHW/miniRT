/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:43 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:40:10 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	check_cylinder_values(char **data)
{
	if (split_length(data) != 6)
		return (print_error("Invalid syntax for cylinder"));
	if (is_vector_compatible(data[1]) == FAILURE)
		return (print_error("Unable to get cylinder position"));
	if (is_vector_compatible(data[2]) == FAILURE)
		return (print_error("Unable to get cylinder direction"));
	if (!is_double_compatible(data[3]))
		return (print_error("Unable to get cylinder diameter"));
	if (!is_double_compatible(data[4]))
		return (print_error("Unable to get cylinder height"));
	if (is_color_compatible(data[5]) == FAILURE)
		return (print_error("Unable to get cylinder color"));
	return (SUCCESS);
}

int	process_cylinder(char **data, t_element *element)
{
	t_cylinder	cylinder;

	if (check_cylinder_values(data) == FAILURE)
		return (FAILURE);
	cylinder.position = extract_vector(data[1]);
	cylinder.direction = extract_vector(data[2]);
	cylinder.diameter = string_to_double(data[3]);
	cylinder.height = string_to_double(data[4]);
	cylinder.color = extract_color(data[5]);
	element->u_element.cylinder = cylinder;
	element->initialized = 1;
	return (SUCCESS);
}

void	clear_cylinder(t_element *element)
{
	if (!element->initialized)
		return ;
	clear_vector(element->u_element.cylinder.position);
	clear_vector(element->u_element.cylinder.direction);
	clear_color(element->u_element.cylinder.color);
}
