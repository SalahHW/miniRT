/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:15:20 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/05 09:30:49 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


void	run_parser(t_context *context);

void    check_list_counter(t_element_list *element_list);
void	check_element_list(t_element_list *element_list);

int	check_element(t_element *element);
int check_ambient_light(t_element *element);
// int check_camera(t_element *element);
// int check_light(t_element *element);
// int check_sphere(t_element *element);
// int check_plane(t_element *element);
// int check_cylinder(t_element *element);

int check_decimal_range(t_decimal *decimal, int min, int max);
int check_color(t_color *color);

#endif
