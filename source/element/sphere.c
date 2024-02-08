/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 17:48:13 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_sphere(char **data, t_element *element)
{
    t_sphere sphere;
    
    if (split_length(data) != 4)
        return ;
    sphere.position = extract_vector(data[1]);
    sphere.diameter = extract_decimal(data[2]);
    sphere.color = extract_color(data[3]);
    element->u_element.sphere = sphere;
    element->initialized = 1;
}

void clear_sphere(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.sphere.position);
    clear_color(element->u_element.sphere.color);
}