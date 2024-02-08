/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:45:41 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 17:50:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_element(t_element *element)
{
    if (element->identifier == ambient_light)
        check_ambient_light(element);
    // else if (element->identifier == camera)
    //     check_camera(element);
    // else if (element->identifier == light)
    //     check_light(element);
    // else if (element->identifier == sphere)
    //     check_sphere(element);
    // else if (element->identifier == plane)
    //     check_plane(element);
    // else if (element->identifier == cylinder)
    //     check_cylinder(element);
    return (SUCCESS);
}

void    check_element_list(t_element_list *element_list)
{
    t_element *element;

    element = element_list->head;
    while (element)
    {
        check_element(element);
        element = element->next;
    }
}