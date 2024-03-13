/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:15:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/13 14:15:11 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_context		t_context;
typedef struct s_element_list	t_element_list;
typedef struct s_element		t_element;
typedef struct s_color			t_color;

int							run_parser(t_context *context);

int							check_list_counter(t_context *context);
int								check_element_list(t_element_list *element_list);

int                             check_vector_range(t_vector vector);
int                             check_vector_normal(t_vector vector);
int								check_ambient_light(t_element *element);
int								check_camera(t_element *element);
int								check_light(t_element *element);
int								check_sphere(t_element *element);
int								check_plane(t_element *element);
int								check_cylinder(t_element *element);
int								check_color(t_color *color);

#endif