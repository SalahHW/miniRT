/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:43:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 11:49:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int run_parser(t_context *context)
{
    if (check_list_counter(context) == FAILURE)
        return (FAILURE);
    if (check_element_list(context->element_list) == FAILURE)
        return (FAILURE);
    context->ambient_light = get_ambient_light(context->element_list);
    context->camera = get_camera(context->element_list);
    context->light = get_light(context->element_list);
    return (SUCCESS);
}