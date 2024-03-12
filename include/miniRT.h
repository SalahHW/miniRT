/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:34:16 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/12 12:31:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 2000
# define SUCCESS 0
# define FAILURE -1

# include "../source/decimal/decimal.h"
# include "../source/element/element.h"
# include "../source/equation/equation.h"
# include "../source/error/error.h"
# include "../source/intersection/intersection.h"
# include "../source/lexer/lexer.h"
# include "../source/light/light.h"
# include "../source/normal_objects/normal.h"
# include "../source/parser/parser.h"
# include "../source/render/render.h"
# include "../source/ressource/context.h"
# include "../source/utils/utils.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

#endif