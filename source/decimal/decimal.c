/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:44:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 05:36:37 by sbouheni         ###   ########.fr       */
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

t_decimal *extract_decimal(char *str)
{
	t_decimal	*decimal;
	char **split;
	int integer_value;
	int decimal_value;

	decimal_value = 0;
	split = ft_split(str, '.');
	if (!split || split_length(split) > 2)
		return (NULL);
	if (!is_int_compatible(split[0]))
	{
		p_free_splited_str(split);
		return (NULL);
	
	}
	if (split_length(split) == 2 && !is_int_compatible(split[1]))
	{
		p_free_splited_str(split);
		return (NULL);
	}
	integer_value = ft_atoi(split[0]);
	if (split_length(split) == 2)
		decimal_value = ft_atoi(split[1]);
	p_free_splited_str(split);
	return (new_decimal(integer_value, decimal_value));
}

void		clear_decimal(t_decimal *decimal)
{
	if (decimal)
		free(decimal);
}