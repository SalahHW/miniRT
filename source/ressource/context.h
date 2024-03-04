/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:04:19 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/29 15:09:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

typedef struct s_rt_file t_rt_file;
typedef struct s_element_list t_element_list;
typedef struct s_mlx_session t_mlx_session;

typedef struct s_context
{
	t_rt_file		*rt_file;
	t_element_list	*element_list;
	t_ambient_light *ambient_light;
	t_camera 		*camera;
	t_light			*light;
	t_mlx_session	*mlx_session;
}					t_context;

t_context			*init_context(char *file_path);
void				clear_context(t_context *context);
void 				quit_program(t_context *context);

#endif