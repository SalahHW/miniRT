/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:32 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/02 13:15:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_camera(char **data, t_element *element)
{
    t_camera camera;

    if (split_length(data) != 4)
        return ;
    if (!is_int_compatible(data[3]))
        return ;
    camera.fov = ft_atoi(data[3]);
    camera.position = extract_vector(data[1]);
    camera.orientation = extract_vector(data[2]);
    element->u_element.camera = camera;
    element->initialized = 1;
}

void clear_camera(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.camera.position);
    clear_vector(element->u_element.camera.orientation);
}
