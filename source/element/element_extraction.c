/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_extraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 06:39:22 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 07:18:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int    extract_element(t_context *context)
{
    t_element   *element;
    char        **data;

    element = init_element();
    if (!element)
        return (FAILURE);
    data = ft_split_white_space(context->rt_file->current_line);
    if (!data)
    {
        free(element);
        return (FAILURE);
    }
    element->identifier = get_element_type(data[0]);
    if (element->identifier == unknown)
    {
        free(element);
        p_free_splited_str(data);
        return (FAILURE);
    }
    process_element(data, element);
    p_free_splited_str(data);
    add_element(context->element_list, element);
    return (SUCCESS);
}