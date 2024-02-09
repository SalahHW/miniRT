/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:32 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/09 19:39:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_camera(char **data, t_element *element)
{
    t_camera camera;

    if (split_length(data) != 4)
        return (print_error("Invalid values for camera"));
    if (!is_double_compatible(data[3]))
        return (print_error("Unable to get camera fov"));
    camera.fov = string_to_double(data[3]);
    camera.position = extract_vector(data[1]);
    if (!camera.position)
        return (print_error("Unable to get camera position"));
    camera.orientation = extract_vector(data[2]);
    if (!camera.orientation)
    {
        clear_vector(camera.position);
        return (print_error("Unable to get camera orientation"));
    }
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
