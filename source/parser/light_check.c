/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:59:07 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:25:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	check_light(t_element *element)
{
	t_light light;

	light = element->u_element.light;
	if (light.brightness < 0 || light.brightness > 1)
		return (print_error("Light brightness is out of range [0 - 1]"));
    if (check_color(light.color) == FAILURE)
        return (print_error("Light color is out of range [0 - 255]"));
    return (SUCCESS);
}