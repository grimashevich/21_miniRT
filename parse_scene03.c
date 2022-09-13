/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:07:06 by eclown            #+#    #+#             */
/*   Updated: 2022/09/13 20:25:11 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_TRGB		*parse_color(char *str);
t_coord		*parse_coord(char *str);
t_alight	*create_alight(float ratio, t_TRGB *color);
t_coord		*create_coord(float x, float y, float z);
t_camera	*create_camera(t_coord *vp, t_coord *vector, int fov);
t_coord		*parse_norm_vector(char *str);

void	*file_format_error(char *str_err)
{
	ft_putstr_fd("Scene file format error: ", 2);
	ft_putstr_fd(str_err, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int	check_alight_args(char **args)
{
	t_TRGB	*color;
	float	ratio;

	if (text_len(args) != 3)
		return (0);
	if (! ft_is_float(args[1]))
		return (0);
	ratio = ft_atof(args[1]);
	if (ratio < 0 || ratio > 1)
		return (0);
	color = parse_color(args[2]);
	if (color == NULL)
		return (0);
	free(color);
	return (1);
}

t_alight	*parse_alight(char *str)
{
	char		**bloks;
	t_alight	*alight;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_alight_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Ambient lightning wrong args"));
	}
	alight = create_alight(ft_atof(bloks[1]), parse_color(bloks[2]));
	free_text(bloks);
	free(str);
	return (alight);
}

int	check_camera_args(char **args)
{
	t_coord	*coord;
	int		fov;

	if (text_len(args) != 4)
		return (0);
	if (! ft_is_integer(args[3]))
		return (0);
	fov = ft_atoi(args[3]);
	if (fov < 0 || fov > 180)
		return (0);
	coord = parse_coord(args[1]);
	if (coord == NULL)
		return (0);
	free(coord);
	coord = parse_norm_vector(args[2]);
	if (coord == NULL)
		return (0);
	free(coord);
	return (1);
}

t_camera	*parse_camera(char *str)
{
	char		**bloks;
	t_camera	*camera;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_camera_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Ambient lightning wrong args"));
	}
	camera = create_camera(
		parse_coord(bloks[1]),
		parse_coord(bloks[2]),
		ft_atod(bloks[3]));
	free_text(bloks);
	free(str);
	return (camera);
}
