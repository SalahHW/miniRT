/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:58 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 04:50:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int check_light_values(char **data)
{
    if (split_length(data) != 4)
        return (print_error("Invalid syntax for light"));
    if (is_vector_compatible(data[1]) == FAILURE)
        return (print_error("Unable to get light position"));
    if (!is_double_compatible(data[2]))
        return (print_error("Unable to get light brightness"));
    if (is_color_compatible(data[3]) == FAILURE)
        return (print_error("Unable to get light color"));
    return (SUCCESS);
}

int	process_light(char **data, t_element *element)
{
    t_light light;

    if (check_light_values(data) == FAILURE)
        return (FAILURE);
    light.position = extract_vector(data[1]);
    light.brightness = string_to_double(data[2]);
    light.color = extract_color(data[3]);
    element->u_element.light = light;
    element->initialized = 1;
    return (SUCCESS);
}

t_light *get_light(t_element_list *list)
{
    t_element *current_element;

    current_element = list->head;
    while (current_element)
    {
        if (current_element->identifier == light)
            return (&current_element->u_element.light);
        current_element = current_element->next;
    }
    return (NULL);
}

void clear_light(t_element *element)
{
    if (!element->initialized)
        return ;
    clear_vector(element->u_element.light.position);
    clear_color(element->u_element.light.color);
}