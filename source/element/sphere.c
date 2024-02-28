/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 05:02:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int check_sphere_values(char **data)
{
    if (split_length(data) != 4)
        return (print_error("Invalid syntax for sphere"));
    if (!is_vector_compatible(data[1]))
        return (print_error("Unable to get sphere position"));
    if (!is_double_compatible(data[2]))
        return (print_error("Unable to get sphere diameter"));
    if (!is_color_compatible(data[3]))
        return (print_error("Unable to get sphere color"));
    return (SUCCESS);
}

int	process_sphere(char **data, t_element *element)
{
    t_sphere sphere;
    
    if (check_sphere_values(data) == FAILURE)
        return (FAILURE);
    sphere.position = extract_vector(data[1]);
    sphere.diameter = string_to_double(data[2]);
    sphere.color = extract_color(data[3]);
    element->u_element.sphere = sphere;
    element->initialized = 1;
    return (SUCCESS);
}

void clear_sphere(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.sphere.position);
    clear_color(element->u_element.sphere.color);
}