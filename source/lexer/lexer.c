/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:43:37 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 03:51:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	run_lexer(t_context *context)
{
	if (open_rt_file(context->rt_file) == FAILURE)
		return (FAILURE);
	if (extract_rt_file_data(context) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
