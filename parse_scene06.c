/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene06.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:46:20 by eclown            #+#    #+#             */
/*   Updated: 2022/09/27 18:24:50 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		*parse_color(char *str);
t_vec		*parse_coord(char *str);
t_vec		*parse_norm_vector(char *str);
int	        check_base_object_args(char **args);
int	        check_sphere_args(char **args);
int	        check_plane_args(char **args);
int	        check_cylinder_args(char **args);
t_sphere	*create_sphere_data(double r, t_vec *orig);
t_plane		*create_plane_data(t_vec *vector, t_vec *orig);
t_cylinder *create_cylinder_data(t_vec *orig,
								 double diam,
								 double h,
								 t_vec *vector);

t_object *create_base_object(enum e_obj_type type, t_color *color)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	if (!object)
		exit_error("malloc error in create_base_object");
	object->mat = ft_calloc(1, sizeof(t_material));
	if (! object->mat)
		exit_error("malloc error in create_base_object (mat)");
	object->mat->color = color;
	object->type = type;
	return (object);
}

t_object	*parse_sphere(char *str)
{
	char			**bloks;
	t_object		*object;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_base_object_args(bloks) == 0 || check_sphere_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Sphere wrong args"));
	}
	object = create_base_object(SPHERE,
								parse_color(bloks[3]));
	object->data = create_sphere_data(ft_atod(bloks[2]), parse_coord(bloks[1]));
	free_text(bloks);
	free(str);
	return (object);
}

t_object	*parse_plane(char *str)
{
	char			**bloks;
	t_object		*object;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_base_object_args(bloks) == 0 || check_plane_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Plane wrong args"));
	}
	object = create_base_object(PLANE,
								parse_color(bloks[3]));
	object->data = create_plane_data(parse_norm_vector(bloks[2]), parse_coord(bloks[1]));
	free_text(bloks);
	free(str);
	return (object);
}

t_object	*parse_cylinder(char *str)
{
	char			**bloks;
	t_object		*object;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_base_object_args(bloks) == 0 || check_cylinder_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Cylinder wrong args"));
	}
	object = create_base_object(CYLINDER,
								parse_color(bloks[3]));
	object->data = create_cylinder_data(parse_coord(bloks[1]),
										ft_atod(bloks[3]),
										ft_atod(bloks[4]),
										parse_norm_vector(bloks[2]));
/*	data = malloc(sizeof(t_cylinder));
	if (!data)
		exit_error("malloc error in parse_sphere");
	data->dir = parse_norm_vector(bloks[2]);
	data->d = ft_atof(bloks[3]);
	data->h = ft_atof(bloks[4]);
	object->data = data;*/
	free_text(bloks);
	free(str);
	return (object);
}
