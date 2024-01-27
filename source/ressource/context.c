/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 03:19:18 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 03:24:28 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_context    *init_context(void)
{
    t_context	*context;

    context = malloc(sizeof(t_context));
    if (!context)
        print_exit_error("Unable to allocate memory for context");
    context->rt_file = NULL;
    context->element_list = init_element_list();
    if (!context->element_list)
    {
        free(context);
        print_exit_error("Unable to allocate memory for element list");
    }
    return (context);
}