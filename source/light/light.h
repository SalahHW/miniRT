/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:45:50 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/11 14:49:04 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct s_context t_context;
typedef struct s_dir_pixel t_dir_pixel;
typedef struct s_vector t_vector;
typedef struct s_light t_light;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;

int		calculate_ambient_light_color(int obj_color, int ambient_color, double factor);
int		search_diffuse_light(t_dir_pixel dir, t_context *minirt);
int		diffuse_light(t_dir_pixel dir, t_light light, t_context *minirt);
int		color_diffuse_light(int light_color, int col_obj, double factor_lux);
int		sum_light(int color_a, int color_b);
int		not_illum(t_vector pos, t_vector dir, t_context *minirt, double distance);
int		intersection_plans_bis(t_vector pos, t_vector dir, t_plane *plane,
			double distance);
int		intersection_spheres_bis(t_vector pos, t_vector dir, t_sphere *sphere,
			double distance);
int		intersection_plan_bis(t_vector pos, t_vector dir, t_plane *plan,
			double distance);
int		intersection_sphere_bis(t_vector pos, t_vector dir, t_sphere *sphere,
			double distance);
int		intersection_cyls_bis(t_vector cam, t_vector dir, t_cylinder *cylinder,
			double distance);
int		intersection_cyl_bis(t_vector cam, t_vector dir, t_cylinder *cylinder, double distance);
int		intersection_cyl2_bis(t_vector cam, t_vector dir, t_cylinder *cylinder,
			double distance);
int		intersection_cyl3_bis(t_vector cam, t_vector dir, t_cylinder *cylinder,
			double distance);

#endif