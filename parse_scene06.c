/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene06.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:46:20 by eclown            #+#    #+#             */
/*   Updated: 2022/09/15 19:52:16 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_TRGB		*parse_color(char *str);
t_coord		*parse_coord(char *str);
int	check_base_object_args(char **args);
int	check_sphere_args(char **args);
int	check_plane_args(char **args);
int	check_cylinder_args(char **args);


t_object	*create_base_object(enum obj_type type, t_coord *coord, t_TRGB *color)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (! object)
		exit_error("malloc error in create_base_object");
	object->type = type;
	object->coord = coord;
	object->color = color;
	object->data = NULL;
	return (object);
}

t_object	*parse_sphere(char *str)
{
	char			**bloks;
	t_object		*object;
	t_sphere_data	*data;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_base_object_args(bloks) == 0 || check_sphere_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Sphere wrong args"));
	}
	object = create_base_object(SPHERE, parse_coord(bloks[1]), parse_color(bloks[3]));
	data = malloc(sizeof(t_sphere_data));
	if (! data)
		exit_error("malloc error in parse_sphere");
	data->diameter = ft_atof(bloks[2]);
	object->data = data;
	free_text(bloks);
	free(str);
	return (object);
}

t_object	*parse_plane(char *str)
{
	//TODO HERE
}