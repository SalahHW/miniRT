/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:19:10 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:20:28 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_cylinder(t_element *element)
{
    t_cylinder cylinder;

    cylinder = element->u_element.cylinder;
    if (check_vector(cylinder.direction) == FAILURE)
        return (print_error("Cylinder orientation is out of range [-1 - 1]"));
    if (check_color(cylinder.color) == FAILURE)
        return (print_error("Cylinder color is out of range [0 - 255]"));
    return (SUCCESS);
}