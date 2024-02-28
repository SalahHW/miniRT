/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:43:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 05:48:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void run_parser(t_context *context)
{
    check_list_counter(context);
    if (check_element_list(context->element_list) == FAILURE)
    {
        clear_context(context);
        exit(EXIT_FAILURE);
    }
        
}