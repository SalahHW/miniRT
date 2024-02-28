/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:10:14 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:13:57 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_plane(t_element *element)
{
    t_plane plane;

    plane = element->u_element.plane;
    if (check_color(plane.color) == FAILURE)
        return (print_error("Plane color is out of range [0 - 255]"));
    if (check_vector(plane.direction) == FAILURE)
        return (print_error("Plane orientation is out of range [-1 - 1]"));
    return (SUCCESS);
}