/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:43 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/09 19:43:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_cylinder(char **data, t_element *element)
{
    t_cylinder cylinder;

    if (split_length(data) != 6)
        return (print_error("Invalid values for cylinder"));
    cylinder.position = extract_vector(data[1]);
    cylinder.direction = extract_vector(data[2]);
    cylinder.diameter = string_to_double(data[3]);
    cylinder.height = string_to_double(data[4]);
    cylinder.color = extract_color(data[5]);
    element->u_element.cylinder = cylinder;
    element->initialized = 1;
    return (SUCCESS);
}

void clear_cylinder(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.cylinder.position);
    clear_vector(element->u_element.cylinder.direction);
    clear_color(element->u_element.cylinder.color);
}