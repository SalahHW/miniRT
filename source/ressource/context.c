/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 03:19:18 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 05:08:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_context    *init_context(void)
{
    t_context	*context;

    context = malloc(sizeof(t_context));
    if (!context)
        print_exit_error("Unable to allocate memory for context");
    context->rt_file = malloc(sizeof(t_rt_file));
    if (!context->rt_file)
    {
        free(context);
        print_exit_error("Unable to allocate memory for rt file");
    }
    context->element_list = init_element_list();
    if (!context->element_list)
    {
        free(context);
        print_exit_error("Unable to allocate memory for element list");
    }
    return (context);
}

void   clear_context(t_context *context)
{
    if (context->rt_file)
        free(context->rt_file);
    if (context->element_list)
        clear_element_list(context->element_list);
    free(context);
}