/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/23 17:26:44 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*get_file_name(char *str);
t_coord			*parse_coord(char *str);
int				check_norm_vector(t_coord *vector);
void			*error_open_file(char *filename);
t_scene			*create_scene(void);
int				open_scene_file(char *filename, int *fd);
int				parse_str_scene(t_scene *scene, char *str, int line_num);

int	check_scene_file_extension(char *filename)
{
	int	strlen;

	strlen = ft_strlen(filename);
	if (filename[strlen - 1] != 't' || filename[strlen - 2] != 'r')
		return (0);
	if (filename[strlen - 3] != '.')
		return (0);
	return (1);
}

t_scene	*parse_scene(char *filename)
{
	int		fd;
	char	*str;
	t_scene	*scene;
	int		parse_error;
	int		line_num;

	if (! open_scene_file(filename, &fd))
		return (error_open_file(filename));
	str = get_next_line(fd);
	scene = create_scene();
	scene->description = get_file_name(filename);
	line_num = 1;
	while (str)
	{
		parse_error = parse_str_scene(scene, str, line_num);
		free(str);
		if (parse_error)
			return (error_open_file(filename));
		str = get_next_line(fd);
		line_num++;
	}
	return (scene);
}

t_object	*create_object(enum e_obj_type type, t_coord *coord,
	t_trgb *color, void *data)
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

t_camera	*create_camera(t_coord *vp, t_coord *vector, int fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (! camera)
		exit_error("malloc error in create_camera");
	camera->view_point = vp;
	camera->vector = vector;
	camera->fov = fov;
	return (camera);
}

t_coord	*parse_norm_vector(char *str)
{
	t_coord	*vector;

	if (! str)
		return (NULL);
	vector = parse_coord(str);
	if (! vector)
		return (NULL);
	if (check_norm_vector(vector) == 0)
	{
		free(vector);
		return (NULL);
	}
	return (vector);
}
