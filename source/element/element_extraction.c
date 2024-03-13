/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_extraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 06:39:22 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 17:09:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int    extract_element(t_context *context, char **data)
{
    t_element   *element;

    element = init_element();
    if (!element)
        return (FAILURE);
    element->identifier = get_element_type(data[0]);
    if (element->identifier == unknown)
    {
        free(element);
        p_free_splited_str(data);
        return (print_error("Unknown element type in file"));
    }
    if (process_element(data, element) == FAILURE)
    {
        clear_element(element);
        p_free_splited_str(data);
        return (FAILURE);
    }
    add_element(context->element_list, element);
    return (SUCCESS);
}