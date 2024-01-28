/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:43 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 06:58:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_cylinder(char **data, t_element *element)
{
}

void clear_cylinder(t_cylinder *cylinder)
{
    clear_vector(cylinder->position);
    clear_vector(cylinder->direction);
    clear_decimal(cylinder->radius);
    clear_decimal(cylinder->height);
    clear_color(cylinder->color);
    free(cylinder);
}