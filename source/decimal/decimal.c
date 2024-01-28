/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:44:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 06:51:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_decimal	*new_decimal(int integer, int decimal)
{
	t_decimal *new_decimal;

	new_decimal = (t_decimal *)malloc(sizeof(t_decimal));
	if (!new_decimal)
		return (NULL);
	new_decimal->integer = integer;
	new_decimal->decimal = decimal;
	return (new_decimal);
}

void		clear_decimal(t_decimal *decimal)
{
	free(decimal);
}