/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:31:12 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 07:01:44 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_plane(char **data, t_element *element)
{
}

void clear_plane(t_plane *plane)
{
    clear_vector(plane->point);
    clear_vector(plane->normal);
    clear_color(plane->color);
    free(plane);
}