/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:11:17 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 14:15:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int check_vector_normal(t_vector vector)
{
    double square_x;
    double square_y;
    double square_z;

    square_x = vector.x * vector.x;
    square_y = vector.y * vector.y;
    square_z = vector.z * vector.z;
    if (square_x + square_y + square_z != 1)
        return (FAILURE);
    return (SUCCESS);
}

int check_vector_range(t_vector vector)
{
    if (vector.x < -1 || vector.x > 1)
        return (FAILURE);
    if (vector.y < -1 || vector.y > 1)
        return (FAILURE);
    if (vector.z < -1 || vector.z > 1)
        return (FAILURE);
    return (SUCCESS);
}