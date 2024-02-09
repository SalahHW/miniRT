/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/09 19:42:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_sphere(char **data, t_element *element)
{
    t_sphere sphere;
    
    if (split_length(data) != 4)
        return (print_error("Invalid values for sphere"));
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