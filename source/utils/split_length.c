/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:31:00 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/29 08:31:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int split_length(char **split)
{
    int i;

    i = 0;
    while (split[i])
        i++;
    return (i);
}