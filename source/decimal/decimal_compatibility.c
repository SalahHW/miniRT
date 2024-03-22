/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_compatibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 04:02:54 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 18:25:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	check_integer_part(char *str)
{
	int	value;

	if (!is_int_compatible(str))
		return (0);
	value = ft_atoi(str);
	if (value > 999 || value < -999)
		return (0);
	return (1);
}

static int	check_decimal_part(char *str)
{
	int	value;

	if (!is_int_compatible(str))
		return (0);
	value = ft_atoi(str);
	if (value < 0 || ft_strlen(str) > 2)
		return (0);
	return (1);
}

int	is_double_compatible(char *str)
{
	char	**split;
	int		result;

	result = 1;
	split = ft_split(str, '.');
	if (!split)
		return (0);
	if (split_length(split) == 1)
	{
		if (!check_integer_part(split[0]))
			result = 0;
	}
	else if (split_length(split) == 2)
	{
		if (!check_integer_part(split[0]) || !check_decimal_part(split[1]))
			result = 0;
	}
	else
		result = 0;
	p_free_splited_str(split);
	return (result);
}
