/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:43:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 06:45:09 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_color *new_color(int red, int green, int blue)
{
    t_color *color;

    color = malloc(sizeof(t_color));
    if (!color)
        return (NULL);
    color->red = red;
    color->green = green;
    color->blue = blue;
    return (color);
}

void clear_color(t_color *color)
{
    free(color);
}