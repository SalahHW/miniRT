/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 05:08:56 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_sphere(char **data, t_element *element)
{
}

void clear_sphere(t_element *element)
{
    clear_vector(element->u_element.sphere.position);
    clear_decimal(element->u_element.sphere.diameter);
    clear_color(element->u_element.sphere.color);
}