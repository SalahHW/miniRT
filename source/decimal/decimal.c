/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:44:29 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/08 04:01:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int is_double_compatible(char *str)
{
	int decimal_point;
	int number;

	decimal_point = 0;
	number = 0;
	if (!*str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			number = 1;
		else if (*str == '.')
		{
			if (decimal_point)
				return (0);
			decimal_point = 1;
		}
		else
			return (0);
		str++;
	}
	return (number);
}

double	string_to_double(char *str)
{
    double number;
    int sign;
    double factor;

    number = 0.0;

    sign = 1;
    factor = 1.0;
    if (*str == '-')
    {
        sign *= -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        number = number * 10 + (*str - '0');
        str++;
    }
    if (*str == '.')
    {
        str++;
        while (ft_isdigit(*str))
        {
            factor /= 10.0;
            number = number + (*str - '0') * factor;
            str++;
        }
    }
    return (number * sign);
}