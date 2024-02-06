/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:44:27 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 06:49:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_color(t_color *color)
{
    if (color->red < 0 || color->red > 255)
        return (FAILURE);
    if (color->green < 0 || color->green > 255)
        return (FAILURE);
    if (color->blue < 0 || color->blue > 255)
        return (FAILURE);
    return (SUCCESS);
}