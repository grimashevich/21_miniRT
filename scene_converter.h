/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/29 20:09:17 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_CONVERTER_H
# define SCENE_CONVERTER_H


#include "minirt.h"

typedef struct s_alight
{
	float	ratio;
	t_color	color;
}	t_alight;

typedef struct s_camera
{
	t_vec			orig;
	t_vec			dir;
	unsigned int	fov;
	t_vec			right;
	t_vec			up;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	double	intens;
	t_color	color;
}	t_light;

typedef struct s_material
{
	t_color	color;
	double	albedo[3];
	double	spec_exp;
}	t_material;

typedef struct s_object
{
	enum e_obj_type	type;
	void			*params;
	int				(*intersect)();
	t_vec			(*get_normal)();
	t_material		mat;
}	t_object;

typedef struct s_sphere_data
{
	t_vec	orig;
	double	r;
}	t_sphere;

typedef struct s_plane_data
{
	t_vec	orig;
	t_vec	normal;
}	t_plane;

typedef struct s_cylinder_data
{
	t_vec	orig;
	t_vec	dir;
	double	d;
	double	h;
}	t_cylinder;



/*typedef struct s_scene
{
	char		*description;
	t_alight	*alight;
	t_camera	*camera;
	t_light		**lights;
	t_object	**objects;
	t_mlx		*mlx;
	t_keys		*keys;
	t_ray		ray;
	double		tnear;
}	t_minirt;*/

#endif	//SCENE_CONVERTER_H