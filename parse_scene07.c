/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene07.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:14 by eclown            #+#    #+#             */
/*   Updated: 2022/09/23 16:45:33 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_t_plane_data(t_plane_data *data);
void	free_t_cylinder_data(t_cylinder_data *data);
void	free_object(t_object *object);

void	free_alight(t_alight *alight)
{
	if (! alight)
		return ;
	if (alight->color)
		free(alight->color);
	free(alight);
}

void	free_camera(t_camera *camera)
{
	if (! camera)
		return ;
	if (camera->view_point)
		free(camera->view_point);
	if (camera->vector)
		free(camera->vector);
	free(camera);
}

void	free_light_array(t_light **light_array)
{
	int	i;

	if (! light_array)
		return ;
	i = 0;
	while (light_array[i])
	{
		if (! light_array[i])
			return ;
		if (light_array[i]->color)
			free(light_array[i]->color);
		if (light_array[i]->light_point)
			free(light_array[i]->light_point);
		free(light_array[i]);
		i++;
	}
	free(light_array);
}

void	free_object_array(t_object **object_array)
{
	int	i;

	if (! object_array)
		return ;
	i = 0;
	while (object_array[i])
		free_object(object_array[i++]);
	free(object_array);
}

void	free_scene(t_scene *scene)
{
	if (! scene)
		return ;
	if (scene->description)
		free(scene->description);
	if (scene->alight)
		free_alight(scene->alight);
	if (scene->camera)
		free_camera(scene->camera);
	if (scene->lights)
		free_light_array(scene->lights);
	if (scene->objects)
		free_object_array(scene->objects);
	free(scene);
}
