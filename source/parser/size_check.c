/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:11:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/22 19:18:31 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	check_size(double size)
{
	if (size < 0 || size > 999)
		return (FAILURE);
	return (SUCCESS);
}
