/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:50:31 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/11 15:56:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

typedef struct s_vector t_vector;

t_vector	get_normal_plan(t_vector n, t_vector cam_to_inter);
t_vector	get_normal_sphere(t_vector intersection, t_vector center);
t_vector	get_normal_cyl(t_vector intersection, t_vector axis, t_vector center);

#endif