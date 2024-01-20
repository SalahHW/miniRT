/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:51:25 by sbouheni          #+#    #+#             */
/*   Updated: 2024/01/20 03:23:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

typedef enum e_element_identifier
{
	null,
	ambient_light,
	camera,
	light,
	sphere,
	plane,
	cylinder,
}							t_element_identifier;

typedef struct s_vector
{
	double					x;
	double					y;
	double					z;
}							t_vector;

typedef struct s_color
{
	int						red;
	int						green;
	int						blue;
}							t_color;

typedef struct s_ambient_light
{
	double					intensity;
	t_color					color;
}							t_ambient_light;

typedef struct s_camera
{
	t_vector				position;
	t_vector				orientation;
	int						fov;
}							t_camera;

typedef struct s_light
{
	t_vector				position;
	double					brightness;
	t_color					color;
}							t_light;

typedef struct s_sphere
{
	t_vector				position;
	double					diameter;
	t_color					color;
}							t_sphere;

typedef struct s_plane
{
	t_vector				point;
	t_vector				normal;
	t_color					color;
}							t_plane;

typedef struct s_cylinder
{
	t_vector				position;
	t_vector				direction;
	double					radius;
	double					height;
	t_color					color;
}							t_cylinder;

typedef struct s_element
{
	t_element_identifier	identifier;
	union
	{
		t_ambient_light		ambient_light;
		t_camera			camera;
		t_light				light;
		t_sphere			sphere;
		t_plane				plane;
		t_cylinder			cylinder;
	} u_element;
	struct s_element		*next;
}							t_element;

typedef struct s_element_list
{
	t_element				*head;
}							t_element_list;



#endif
