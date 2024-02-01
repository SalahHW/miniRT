/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 05:06:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_light(char **data, t_element *element)
{
}

void clear_light(t_element *element)
{
    clear_vector(element->u_element.light.position);
    clear_decimal(element->u_element.light.brightness);
    clear_color(element->u_element.light.color);
}