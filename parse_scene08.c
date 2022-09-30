/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene08.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:14 by eclown            #+#    #+#             */
/*   Updated: 2022/09/29 20:13:10 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_t_plane_data(t_plane *data);
void	free_t_cylinder_data(t_cylinder *data);
void	free_object(t_object *object);

void	free_t_plane_data(t_plane *data)
{
	if (! data)
		return ;
	if (data->normal)
		free(data->normal);
	free(data);
}

void	free_t_cylinder_data(t_cylinder *data)
{
	if (! data)
		return ;
	if (data->dir)
		free(data->dir);
	free(data);
}

void	free_material(t_material *mat)
{
	if (! mat)
		return ;
	if (mat->color)
		free(mat->color);
	free(mat);
}

void	free_object(t_object *object)
{
	if (! object)
		return ;
	if (! object->mat)
		free_material(object->mat);
	if (object->type == SPHERE && object->params)
		free(object->params);
	if (object->type == PLANE && object->params)
		free_t_plane_data(object->params);
	if (object->type == CYLINDER && object->params)
		free_t_cylinder_data(object->params);
	free(object);
}
