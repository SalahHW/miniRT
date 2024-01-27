/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 04:34:16 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/27 06:55:56 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define SUCCESS 0
# define FAILURE -1

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

t_context			*init_context(void);

#endif
