/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:19:10 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 14:19:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_cylinder(t_element *element)
{
    t_cylinder cylinder;

    cylinder = element->u_element.cylinder;
    if (check_color(cylinder.color) == FAILURE)
        return (print_error("Cylinder color is out of range [0 - 255]"));
    if (check_vector_range(*cylinder.direction) == FAILURE)
        return (print_error("Cylinder orientation is out of range [-1 - 1]"));
    if (check_vector_normal(*cylinder.direction) == FAILURE)
        return (print_error("Cylinder orientation vector is not normalized"));
    return (SUCCESS);
}