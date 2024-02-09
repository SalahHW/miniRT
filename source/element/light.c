/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/09 19:43:16 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	process_light(char **data, t_element *element)
{
    t_light light;

    if (split_length(data) != 4)
        return (print_error("Invalid values for light"));
    light.position = extract_vector(data[1]);
    light.brightness = string_to_double(data[2]);
    light.color = extract_color(data[3]);
    element->u_element.light = light;
    element->initialized = 1;
    return (SUCCESS);
}

void clear_light(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.light.position);
    clear_color(element->u_element.light.color);
}