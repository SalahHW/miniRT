/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:43:55 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 04:45:17 by sbouheni         ###   ########.fr       */
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

t_color *extract_color(char *str)
{
    t_color *color;
    char **split;
    
    split = ft_split(str, ',');
    if (!split || split_length(split) != 3)
        return (NULL);
    if (!is_int_compatible(split[0]) || !is_int_compatible(split[1]) || !is_int_compatible(split[2]))
    {
        p_free_splited_str(split);
        return (NULL);
    }
    color = new_color(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
    p_free_splited_str(split);
    return (color);
}

void clear_color(t_color *color)
{
    if (color)
        free(color);
}