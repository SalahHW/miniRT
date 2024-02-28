/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:54:24 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:17:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	check_ambient_light(t_element *element)
{
	t_ambient_light ambient_light;

	ambient_light = element->u_element.ambient_light;
	if (ambient_light.intensity < 0 || ambient_light.intensity > 1)
		return (print_error("Anbient ligth intensity is out of range"));
	if (check_color(ambient_light.color) == FAILURE)
		return (print_error("Anbient ligth color is out of range [0 - 255]"));
	return (SUCCESS);
}