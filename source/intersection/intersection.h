/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:38:35 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/19 17:23:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

typedef struct s_context	t_context;
typedef struct s_vector		t_vector;

typedef struct s_dir_pixel
{
	t_vector				dir_pixel;
	t_vector				*intersection;
	t_vector				n;
	double					dist;
	int						col_obj;
	int						color_ambient;
	int						diffuse_light;
	int						did_it_touch;
}							t_dir_pixel;

typedef struct s_base
{
	t_vector	pos;
	t_vector	u;
	t_vector	v;
	t_vector	w;
}			t_base;

void						intersection(t_vector camera_position,
								t_dir_pixel *pixel, t_element_list *list);
void						intersection_plan(t_vector camera_posititon,
								t_dir_pixel *pixel, t_plane plane);
void						intersection_sphere(t_vector camera_posititon,
								t_dir_pixel *pixel, t_sphere sphere);
void						intersection_cylinder(t_vector camera_posititon,
								t_dir_pixel *pixel, t_cylinder cylinder);
int		not_in_range(t_vector intersection, t_cylinder cyl);
double	get_a_cyl(t_vector dir, t_cylinder cyl);
double	get_b_cyl(t_vector dir, t_cylinder cyl, t_vector ca);
double	get_c_cyl(t_cylinder cyl, t_vector ca);


int		init_projection(t_base *base_cam, t_camera *cam,
			double dist_cam, t_context *minirt);
void	initialize_and_update_pixel(t_dir_pixel *pixel);
int		allocate_dir_pixel_array(t_context *minirt);
int		allocate_dir_pixel_row(t_context *minirt, int y);
int		allocate_intersection(t_context *minirt, int y, int x);

#endif