/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:07:54 by eclown            #+#    #+#             */
/*   Updated: 2022/09/09 18:23:27 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere_data *create_sphere_data(float	diameter)
{
	t_sphere_data	*data;

	data = malloc(sizeof(t_sphere_data));
	if (! data)
		exit_error("malloc error in create_sphere_data");
	data->diameter = diameter;
	return (data);
}

t_plane_data *create_plane_data(t_coord	*vector)
{
	t_plane_data	*data;

	data = malloc(sizeof(t_plane_data));
	if (! data)
		exit_error("malloc error in create_plane_data");
	data->vector = vector;
	return (data);
	
}

t_cylinder_data *create_cylinder_data(float diam, float h, t_coord *vector)
{
	t_cylinder_data	*data;

	data = malloc(sizeof(t_cylinder_data));
	if (! data)
		exit_error("malloc error in create_cylinder_data");
	data->diameter = diam;
	data->vector = vector;
	data->height = h;
	return (data);
}
