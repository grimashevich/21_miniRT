/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:51:29 by eclown            #+#    #+#             */
/*   Updated: 2022/09/19 13:53:58 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_light_count(t_light	**lights);

t_alight	*create_alight(float ratio, t_TRGB *color)
{
	t_alight	*alight;

	alight = malloc(sizeof(t_alight));
	if (! alight)
		exit_error("malloc error in create_alight");
	alight->ratio = ratio;
	alight->color = color;
	return (alight);
}

t_coord	*create_coord(float x, float y, float z)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	if (! coord)
		exit_error("malloc error in create_coord");
	coord->x = x;
	coord->y = y;
	coord->z = z;
	return (coord);
}
t_TRGB	*create_TRGB(int transp, int r, int g, int b)
{
	t_TRGB	*rgb;
	
	rgb = malloc(sizeof(t_TRGB));
	if (! rgb)
		exit_error("malloc error in create_TRGB");
	rgb->transp = transp;
	rgb->R = r;
	rgb->G = g;
	rgb->B = b;
	return (rgb);
}

void add_light_to_array(t_light ***array, t_light *new_light)
{
	t_light **new_array;
	t_light **old_array;
	int	i;

	old_array = *array;
	i = get_light_count(old_array);
	new_array = malloc(sizeof(t_light *) * (i + 2));
	if (! new_array)
		exit_error("malloc error in add_light_to_array");
	i = 0;
	while (old_array && old_array[i])
	{
	   new_array[i] = old_array[i];
	   i++;
	}
	new_array[i++] = new_light;
	new_array[i] = NULL;
	if (old_array != NULL)
		free(old_array);
	*array = new_array;
}

t_light *create_light(t_coord *point, float brightness, t_TRGB *color)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	if (! light)
		exit_error("malloc error in create_light");
	light->light_point = point;
	light->brightness = brightness;
	if (color != NULL)
		light->color = color;
	else
		light->color = NULL;
	return (light);
}
