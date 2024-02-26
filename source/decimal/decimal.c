/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:44:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/26 18:35:22 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	is_double_compatible(char *str)
{
	char	**split;
	int		integer_part;
	int		decimal_part;

	split = ft_split(str, '.');
	if (!split)
		return (0);
	if (split_length(split) != 2 || !is_int_compatible(split[0])
		|| !is_int_compatible(split[1]))
	{
		p_free_splited_str(split);
		return (0);
	}
	integer_part = ft_atoi(split[0]);
	decimal_part = ft_atoi(split[1]);
	if (integer_part > 999 || integer_part < -999 || decimal_part < 0
		|| ft_strlen(split[1]) > 2)
	{
		p_free_splited_str(split);
		return (0);
	}
	p_free_splited_str(split);
	return (1);
}

double	string_to_double(char *str)
{
	int integer_part;
	int decimal_part;
	char **split;
	double result;

	split = ft_split(str, '.');
    if (!split)
        return (0);
	integer_part = ft_atoi(split[0]);
	decimal_part = ft_atoi(split[1]);
	result = integer_part + (decimal_part / pow(10, ft_strlen(split[1])));
    if (*split[0] == '-')
        result *= -1;
	p_free_splited_str(split);
	return (result);
}