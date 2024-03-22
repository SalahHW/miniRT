/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:44:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:24:54 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static double	handle_simple_double(char *str)
{
	double	result;

	result = ft_atoi(str);
	return (result);
}

static double	handle_double(char *integer_part, char *decimal_part)
{
	double	result;
	int		integer;
	int		decimal;

	integer = ft_atoi(integer_part);
	decimal = ft_atoi(decimal_part);
	result = integer + (decimal / pow(10, ft_strlen(decimal_part)));
	if (*integer_part == '-')
		result *= -1;
	return (result);
}

double	string_to_double(char *str)
{
	char	**split;
	double	result;

	split = ft_split(str, '.');
	if (!split)
		return (0);
	if (split_length(split) == 1)
		result = handle_simple_double(split[0]);
	else
		result = handle_double(split[0], split[1]);
	p_free_splited_str(split);
	return (result);
}
