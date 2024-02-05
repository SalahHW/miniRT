/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:54:24 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/05 08:01:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_ambient_light(t_element *element)
{
    t_decimal *intensity;
    int intensity_min;
    int intensity_max;

    intensity = element->u_element.ambient_light.intensity;
    intensity_min = 0;
    intensity_max = 1;
    
    if (check_decimal_range(intensity, intensity_min, intensity_max) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}