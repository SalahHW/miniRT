/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:34:16 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 03:14:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../source/element/element.h"
# include "../source/error/error.h"
# include "../source/lexer/lexer.h"
# include "../source/parser/parser.h"
# include "../source/utils/utils.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_context
{
	t_rt_file		*rt_file;
	t_element_list	*element_list;
}					t_context;

#endif
