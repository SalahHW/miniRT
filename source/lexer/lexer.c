/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:43:37 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 08:55:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	run_lexer(t_context *context)
{
	printf("Elements extraction started\n");
	if (extract_rt_file_data(context) == FAILURE)
		return (FAILURE);
	printf("Elements extracted successfully\n");
	return (SUCCESS);
}
