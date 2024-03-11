/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:13:06 by sbouheni          #+#    #+#             */
/*   Updated: 2024/03/06 15:17:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_H
# define EQUATION_H

typedef struct s_vector	t_vector;

t_vector	sum_vec(t_vector u, t_vector v);
t_vector	diff_vec(t_vector u, t_vector v);
t_vector	prod_nb_vec(double k, t_vector u);
double		prod_scal(t_vector u, t_vector v);
double		norm_vec(t_vector u);
t_vector	prod_vec(t_vector u, t_vector v);
double		find_sol(double sol1, double sol2);
double		sol_quadratic_equation(double a, double b, double c);

#endif