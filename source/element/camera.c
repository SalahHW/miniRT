/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:32 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/27 17:04:26 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int check_camera_values(char **data)
{
    if (split_length(data) != 4)
        return (print_error("Invalid syntax for camera"));
    if (is_vector_compatible(data[1]) == FAILURE)
        return (print_error("Unable to get camera position"));
    if (is_vector_compatible(data[2]) == FAILURE)
        return (print_error("Unable to get camera orientation"));
    if (!is_double_compatible(data[3]))
        return (print_error("Unable to get camera fov"));
    return (SUCCESS);
}

int	process_camera(char **data, t_element *element)
{
    t_camera camera;

    if (check_camera_values(data) == FAILURE)
        return (FAILURE);
    camera.position = extract_vector(data[1]);
    camera.orientation = extract_vector(data[2]);
    camera.fov = string_to_double(data[3]);
    element->u_element.camera = camera;
    element->initialized = 1;
    return (SUCCESS);
}

void clear_camera(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.camera.position);
    clear_vector(element->u_element.camera.orientation);
}
