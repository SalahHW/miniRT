/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 04:51:25 by sbouheni          #+#    #+#             */
/*   Updated: 2024/02/27 16:47:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

typedef struct s_context	t_context;

typedef enum e_element_identifier
{
	unknown,
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
	t_color					*color;
}							t_ambient_light;

typedef struct s_camera
{
	t_vector				*position;
	t_vector				*orientation;
	double					fov;
}							t_camera;

typedef struct s_light
{
	t_vector				*position;
	double					brightness;
	t_color					*color;
}							t_light;

typedef struct s_sphere
{
	t_vector				*position;
	double					diameter;
	t_color					*color;
}							t_sphere;

typedef struct s_plane
{
	t_vector				*position;
	t_vector				*direction;
	t_color					*color;
}							t_plane;

typedef struct s_cylinder
{
	t_vector				*position;
	t_vector				*direction;
	double					diameter;
	double					height;
	t_color					*color;
}							t_cylinder;

typedef struct s_element
{
	t_element_identifier	identifier;
	int						initialized;
	union					u_element
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
	t_element				*tail;
	int						count;
	int						ambient_light_count;
	int						camera_count;
	int						light_count;
	int						sphere_count;
	int						plane_count;
	int						cylinder_count;
}							t_element_list;

t_element					*init_element(void);
t_element_list				*init_element_list(void);

int							is_vector_compatible(char *str);
t_vector					*new_vector(double x, double y, double z);
t_vector					*extract_vector(char *str);
int							is_color_compatible(char *str);
t_color						*new_color(int red, int green, int blue);
t_color						*extract_color(char *str);

void						clear_element_list(t_element_list *list);
int							extract_element(t_context *context);
t_element_identifier		get_element_type(char *str);
void						add_element(t_element_list *list,
								t_element *element);

int							process_element(char **data, t_element *element);
int							process_ambient_light(char **data,
								t_element *element);
int							process_light(char **data, t_element *element);
int							process_camera(char **data, t_element *element);
int							process_sphere(char **data, t_element *element);
int							process_plane(char **data, t_element *element);
int							process_cylinder(char **data, t_element *element);

void						clear_vector(t_vector *vector);
void						clear_color(t_color *color);
void						clear_element(t_element *element);
void						clear_ambient_light(t_element *element);
void						clear_camera(t_element *element);
void						clear_light(t_element *element);
void						clear_sphere(t_element *element);
void						clear_plane(t_element *element);
void						clear_cylinder(t_element *element);

#endif