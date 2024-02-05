/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:05:04 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/04 16:43:42 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_decimal_range(t_decimal *decimal, int min, int max)
{
    if (decimal->integer < min && decimal->decimal < 0)
        return (FAILURE);
    if (decimal->integer > max)
        return (FAILURE);
    if (decimal->integer == max && decimal->decimal > 0)
        return (FAILURE);
    return (SUCCESS);
}