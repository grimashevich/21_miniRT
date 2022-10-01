/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:14:06 by eclown            #+#    #+#             */
/*   Updated: 2022/09/23 17:33:32 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_converter.h"

t_alight *convert_alight(t_alight_p *in)
{
	t_alight *out;

	out = ft_calloc(1, sizeof(t_alight));
	if (! out)
		exit_error("Malloc error in convert_alight");
	out->ratio = in->ratio;
	out->color = *(in->color);
	return (out);
}

t_camera *convert_camera(t_camera_p *in)
{
	t_camera	*out;

	out = ft_calloc(1, sizeof(t_camera));
	if (! out)
		exit_error("Malloc error in convert_camera");
	out->orig = *(in->orig);
	out->dir = *(in->dir);
	return (out);
}

t_light *convert_light(t_light_p *in)
{
	t_light	*out;

	out = ft_calloc(1, sizeof(t_light));
	if (! out)
		exit_error("Malloc error in convert_light");
	out->pos = *(in->pos);
	out->intens = in->intens;
	out->color = *(in->color);
	return (out);
}

t_material *convert_material(t_material_p *in)
{
	t_material	*out;

	out = ft_calloc(1, sizeof(t_material));
	if (! out)
		exit_error("Malloc error in convert_material");
	out->color = *(in->color);
	out->albedo[0] = in->albedo[0];
	out->albedo[1] = in->albedo[1];
	out->albedo[2] = in->albedo[2];
	return (out);
}

//TODO MOVE
void	free_material(t_material_p *mat);

t_object *convert_object(t_object_p *in)
{
	t_object		*out;
	t_material_p	*mat;

	out = ft_calloc(1, sizeof(t_object));
	if (! out)
		exit_error("Malloc error in convert_object");
	out->params = in->params;
	mat = in->mat;
	out->mat = *convert_material(in->mat);
	free_material(mat);
	out->params = in->params;
	return (out);
}

t_sphere *convert_sphere(t_sphere_p *in)
{
	t_sphere	*out;

	out = ft_calloc(1, sizeof(t_sphere));
	if (! out)
		exit_error("Malloc error in convert_sphere");

	return (out);
}

t_plane *convert_plane(t_plane_p *in)
{
	t_plane	*out;

	out = ft_calloc(1, sizeof(t_plane));
	if (! out)
		exit_error("Malloc error in convert_plane");

	return (out);
}

t_cylinder *convert_cylinder(t_cylinder_p *in)
{
	t_cylinder	*out;

	out = ft_calloc(1, sizeof(t_cylinder));
	if (! out)
		exit_error("Malloc error in convert_cylinder");

	return (out);
}
