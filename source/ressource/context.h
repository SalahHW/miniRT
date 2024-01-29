/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:04:19 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/29 06:14:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

typedef struct s_rt_file t_rt_file;
typedef struct s_element_list t_element_list;

typedef struct s_context
{
	t_rt_file		*rt_file;
	t_element_list	*element_list;
}					t_context;

t_context			*init_context(char *file_path);
void				clear_context(t_context *context);

#endif