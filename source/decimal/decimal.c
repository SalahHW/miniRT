/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:44:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/29 07:22:42 by sbouheni         ###   ########.fr       */
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

	split = ft_split(str, '.');
	if (!split || ft_strlen(split) != 2)
		return (NULL);
	if (!is_int_compatible(split[0] || !is_int_compatible(split[1])))
	{
		p_free_splited_str(split);
		return (NULL);	
	}
	decimal = new_decimal(ft_atoi(split[0]), ft_atoi(split[1]));
	p_free_splited_str(split);
	return (decimal);
}

void		clear_decimal(t_decimal *decimal)
{
	free(decimal);
}