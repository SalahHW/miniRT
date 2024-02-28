/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:12 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 05:03:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int check_plane_values(char **data)
{
    if (split_length(data) != 4)
        return (print_error("Invalid syntax for plane"));
    if (!is_vector_compatible(data[1]))
        return (print_error("Unable to get plane position"));
    if (!is_vector_compatible(data[2]))
        return (print_error("Unable to get plane direction"));
    if (!is_color_compatible(data[3]))
        return (print_error("Unable to get plane color"));
    return (SUCCESS);
}

int	process_plane(char **data, t_element *element)
{
    t_plane plane;
    
    if (check_plane_values(data) == FAILURE)
        return (FAILURE);
    plane.position = extract_vector(data[1]);
    plane.direction = extract_vector(data[2]);
    plane.color = extract_color(data[3]);
    element->u_element.plane = plane;
    element->initialized = 1;  
    return (SUCCESS);
}

void clear_plane(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.plane.position);
    clear_vector(element->u_element.plane.direction);
    clear_color(element->u_element.plane.color);
}