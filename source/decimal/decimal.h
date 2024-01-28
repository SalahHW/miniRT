/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 05:42:04 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/28 05:51:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECIMAL_H
# define DECIMAL_H

typedef struct s_decimal
{
	int	integer;
	int	decimal;
}		t_decimal;

t_decimal *new_decimal(int integer, int decimal);

#endif