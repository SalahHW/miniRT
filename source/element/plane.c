/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:12 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 05:08:12 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_plane(char **data, t_element *element)
{
}

void clear_plane(t_element *element)
{
    clear_vector(element->u_element.plane.position);
    clear_vector(element->u_element.plane.direction);
    clear_color(element->u_element.plane.color);
}