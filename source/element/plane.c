/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:12 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/02 18:45:16 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_plane(char **data, t_element *element)
{
    t_plane plane;
    
    if (split_length(data) != 4)
        return ;
    plane.position = extract_vector(data[1]);
    plane.direction = extract_vector(data[2]);
    plane.color = extract_color(data[3]);
    element->u_element.plane = plane;
    element->initialized = 1;
}

void clear_plane(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.plane.position);
    clear_vector(element->u_element.plane.direction);
    clear_color(element->u_element.plane.color);
}