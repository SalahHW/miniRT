/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:43 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 05:05:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_cylinder(char **data, t_element *element)
{
}

void clear_cylinder(t_element *element)
{
    clear_vector(element->u_element.cylinder.position);
    clear_vector(element->u_element.cylinder.direction);
    clear_decimal(element->u_element.cylinder.diameter);
    clear_decimal(element->u_element.cylinder.height);
    clear_color(element->u_element.cylinder.color);
}