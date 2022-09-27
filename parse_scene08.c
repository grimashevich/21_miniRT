/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene08.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:14 by eclown            #+#    #+#             */
/*   Updated: 2022/09/27 18:24:50 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_t_plane_data(t_plane_data *data);
void	free_t_cylinder_data(t_cylinder_data *data);
void	free_object(t_object *object);

void	free_t_plane_data(t_plane_data *data)
{
	if (! data)
		return ;
	if (data->normal)
		free(data->normal);
	free(data);
}

void	free_t_cylinder_data(t_cylinder_data *data)
{
	if (! data)
		return ;
	if (data->vector)
		free(data->vector);
	free(data);
}

void	free_object(t_object *object)
{
	if (! object)
		return ;
	if (object->coord)
		free(object->coord);
	if (object->color)
		free(object->color);
	if (object->type == SPHERE && object->data)
		free(object->data);
	if (object->type == PLANE && object->data)
		free_t_plane_data(object->data);
	if (object->type == CYLINDER && object->data)
		free_t_cylinder_data(object->data);
	free(object);
}
