/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:29:06 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 06:59:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void check_list_counter(t_context *context)
{
    if (context->element_list->ambient_light_count < 1)
        parser_error(context, "No ambient light found");
    if (context->element_list->ambient_light_count > 1)
        parser_error(context, "Too many ambient lights found");
    if (context->element_list->camera_count < 1)
        parser_error(context, "No camera found");
    if (context->element_list->camera_count > 1)
        parser_error(context, "Too many cameras found");
    if (context->element_list->light_count < 1)
        parser_error(context, "No light found");
    if (context->element_list->light_count > 1)
        parser_error(context, "Too many lights found");
}