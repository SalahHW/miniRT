/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:30:32 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/01 05:01:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	process_camera(char **data, t_element *element)
{
}

void clear_camera(t_element *element)
{
    clear_vector(element->u_element.camera.position);
    clear_vector(element->u_element.camera.orientation);
    free(camera);
}
