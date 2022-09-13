/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:07:54 by eclown            #+#    #+#             */
/*   Updated: 2022/09/12 20:23:18 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_TRGB	*create_TRGB(int transp, int r, int g, int b);
t_coord	*create_coord(float x, float y, float z);

t_sphere_data	*create_sphere_data(float diameter)
{
	t_sphere_data	*data;

	data = malloc(sizeof(t_sphere_data));
	if (! data)
		exit_error("malloc error in create_sphere_data");
	data->diameter = diameter;
	return (data);
}

t_plane_data	*create_plane_data(t_coord	*vector)
{
	t_plane_data	*data;

	data = malloc(sizeof(t_plane_data));
	if (! data)
		exit_error("malloc error in create_plane_data");
	data->vector = vector;
	return (data);
}

t_cylinder_data	*create_cylinder_data(float diam, float h, t_coord *vector)
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

/* 
str: str with 3 or 4 integers separated by comma
ex: 0,5,100,35
*/
t_TRGB	*parse_color(char *str)
{
	t_TRGB	*color;
	char	**params;
	int		count;
	int		transp;

	if (str == NULL)
		return (NULL);
	params = ft_split_new(str, ',');
	count = text_len(params);
	if (count > 4 || count < 3 || ! is_all_pos_int(params))
	{
		free_text(params);
		return (NULL);
	}
	transp = 0;
	if (count == 4)
		transp = (int)(unsigned char) ft_atoi(params[0]);
	color = create_TRGB(transp, ft_atoi(params[count - 3]),
			ft_atoi(params[count - 2]), ft_atoi(params[count - 1]));
	color->R = (int)(unsigned char) color->R;
	color->G = (int)(unsigned char) color->G;
	color->B = (int)(unsigned char) color->B;
	free_text(params);
	return (color);
}

/* 
str: str with 3 or 4 integers separated by comma
ex: 0.5,5.15,-100,35
*/
t_coord	*parse_coord(char *str)
{
	t_coord	*coord;
	char	**params;
	int		count;

	if (str == NULL)
		return (NULL);
	params = ft_split_new(str, ',');
	count = text_len(params);
	if (count != 3 || ! is_all_float(params))
	{
		free_text(params);
		return (NULL);
	}
	coord = create_coord(ft_atof(params[0]), ft_atof(params[1]), ft_atof(params[2]));
	free_text(params);
	return (coord);
}