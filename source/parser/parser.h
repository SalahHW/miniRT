/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:15:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/06 17:45:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_context		t_context;
typedef struct s_element_list	t_element_list;
typedef struct s_element		t_element;
typedef struct s_color			t_color;

void							run_parser(t_context *context);

void							check_list_counter(t_context *context);
void							check_element_list(t_element_list *element_list);

int								check_element(t_element *element);
int								check_ambient_light(t_element *element);
// int check_camera(t_element *element);
// int check_light(t_element *element);
// int check_sphere(t_element *element);
// int check_plane(t_element *element);
// int check_cylinder(t_element *element);
int								check_color(t_color *color);

#endif