/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:11:17 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/28 10:11:41 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_vector(t_vector *vector)
{
    if (vector->x < -1 || vector->x > 1)
        return (FAILURE);
    if (vector->y < -1 || vector->y > 1)
        return (FAILURE);
    if (vector->z < -1 || vector->z > 1)
        return (FAILURE);
    return (SUCCESS);
}