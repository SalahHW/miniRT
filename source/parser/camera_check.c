/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 05:49:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:27:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_camera(t_element *element)
{
    t_camera camera;

    camera = element->u_element.camera;
    if (camera.fov < 0 || camera.fov > 180)
        return (print_error("Camera fov is out of range [0 - 180]"));
    if (check_vector(camera.orientation) == FAILURE)
        return (print_error("Camera orientation is out of range [-1 - 1]"));
    return (SUCCESS);
}
