/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:10:14 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 14:17:54 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_plane(t_element *element)
{
    t_plane plane;

    plane = element->u_element.plane;
    if (check_color(plane.color) == FAILURE)
        return (print_error("Plane color is out of range [0 - 255]"));
    if (check_vector_range(*plane.direction) == FAILURE)
        return (print_error("Plane orientation is out of range [-1 - 1]"));
    if (check_vector_normal(*plane.direction) == FAILURE)
        return (print_error("Plane orientation vector is not normalized"));
    return (SUCCESS);
}