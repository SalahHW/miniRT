/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 03:19:18 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 17:52:31 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_context    *init_context(char *rt_file_path)
{
    t_context	*context;

    context = malloc(sizeof(t_context));
    if (!context)
        print_exit_error("Unable to allocate memory for context");
    context->rt_file = open_rt_file(rt_file_path);
    if (!context->rt_file)
    {
        free(context);
        exit(EXIT_FAILURE);
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
        clear_file(context->rt_file);
    if (context->element_list)
        clear_element_list(context->element_list);
    free(context);
}