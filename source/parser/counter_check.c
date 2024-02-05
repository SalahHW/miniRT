/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:29:06 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/05 09:35:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void check_list_counter(t_element_list *list)
{
    if (list->ambient_light_count < 1)
        lexer_error("No ambient light found");
    if (list->ambient_light_count > 1)
        lexer_error("Too many ambient lights found");
    if (list->camera_count < 1)
        lexer_error("No camera found");
    if (list->camera_count > 1)
        lexer_error("Too many cameras found");
    if (list->light_count < 1)
        lexer_error("No light found");
    if (list->light_count > 1)
        lexer_error("Too many lights found");
}