/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/12 20:12:53 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere_data *create_sphere_data(float	diameter);
t_plane_data *create_plane_data(t_coord	*vector);
t_cylinder_data *create_cylinder_data(float diam, float h, t_coord *vector);

int check_scene_file_extension(char *filename)
{
	int strlen = ft_strlen(filename);

	if (filename[strlen - 1] != 't' || filename[strlen - 2] != 'r')
	   return (0);
	if (filename[strlen - 3] != '.')
	   return (0);
	return (1);
}

t_scene *parse_t_scene(char *filename)
{
	int fd;

	if (check_scene_file_extension(filename) == 0)
	{
	   ft_putstr_fd("Incorrect scene filename\n", 2);
	   return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
	   ft_putstr_fd("Error open file ", 2);
	   ft_putstr_fd(filename, 2);
	   ft_putstr_fd("n", 2);
	   return (NULL);
	}
	return (NULL); //FIXME
}

t_object	*create_object(enum obj_type type, t_coord *coord, t_TRGB *color, void *data)
{
	t_object	*obj;

	obj = malloc(sizeof(obj));
	if (! obj)
		exit_error("malloc error in create_object");
	obj->type = type;
	obj->coord = coord;
	obj->color = color;
	obj->data = data;
	return (obj);
}
