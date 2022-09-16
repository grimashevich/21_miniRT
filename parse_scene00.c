/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/16 17:00:15 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere_data	*create_sphere_data(float	diameter);
t_plane_data	*create_plane_data(t_coord	*vector);
t_cylinder_data	*create_cylinder_data(float diam, float h, t_coord *vector);
t_coord			*parse_coord(char *str);
int				check_norm_vector(t_coord *vector);
void			*error_open_file(char *filename);
t_scene 		*init_scene(void);
void			add_light_to_array(t_light ***array, t_light *new_light);
t_alight		*parse_alight(char *str);
t_light			*parse_light(char *str);
t_camera		*parse_camera(char *str);

int	parse_error(int line_num, char *str)
{
	ft_putstr_fd("Parsing error in line ", 2);
	ft_putstr_fd(ft_itoa(str), 2);
	ft_putstr_fd(". ", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

int	add_alight_to_scene(t_scene *scene, char *str, int line_num)
{
	if (scene->alight)
	{
		free(str);
			return (parse_error(line_num, "There is second ambient light in scene."));
	}
	scene->alight = parse_alight(str);
	free(str);
	if (scene->alight == NULL)
		return (parse_error(line_num, "Ambient light parse error"));
	return (0);	
}

static int	get_light_count(t_light	**lights)
{
	int	i;

	if (lights == NULL)
		return (0);
	while (lights[i])
		i++;
	return (i);
}

int	add_light_to_scene(t_scene *scene, char *str, int line_num)
{
	int	lights_count;

	lights_count = get_light_count(scene->lights);
	if (IS_BONUS_PART == 0 && lights_count > 0)
	{
		free(str);
		return (parse_error(line_num, "There is second light in scene."));
	}
	add_light_to_array(&(scene->lights), parse_light(str));
	free(str);
	if (lights_count == get_light_count(scene->lights))
		return (parse_error(line_num, "Light parse error"));
	return (0);
}

int	add_camera_to_scene(t_scene *scene, char *str, int line_num)
{
	if (scene->camera)
	{
		free(str);
		return (parse_error(line_num, "There is second camera in scene."));

	}
	scene->camera  = parse_camera(str);
	free(str);
	if (scene->camera == NULL)
		return (parse_error(line_num, "Camera parse error"));
	return (0);
}

int	add_object_to_scene(t_scene *scene, char *str, int line_num)
{
	
	free(str);
	//TODO HERE
}

int	parse_str_scene(t_scene *scene, char *str, int line_num)
{
	str = ft_strtrim(str, " \t\n");
	if (str[0] == 'A' && ft_is_spc(str[1]))
	{
		
	}
	else if (str[0] == 'C' && ft_is_spc(str[1]))
	{
		
	}
	else if (str[0] == 'L' && ft_is_spc(str[1]))
	{
		
	}
	else if (str[0] == 'L' && ft_is_spc(str[1]))
	{
		
	}
	else if (str[0] == 'L' && ft_is_spc(str[1]))
	{
		
	}
	else if (str[0] == 'L' && ft_is_spc(str[1]))
	{
		
	}	
	free(str);
	return (0);
	//TODO and HERE
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int check_scene_file_extension(char *filename)
{
	int strlen = ft_strlen(filename);

	if (filename[strlen - 1] != 't' || filename[strlen - 2] != 'r')
	   return (0);
	if (filename[strlen - 3] != '.')
	   return (0);
	return (1);
}

t_scene *parse_scene(char *filename)
{
	int		fd;
	char	*str;

	if (check_scene_file_extension(filename) == 0)
	{
	   ft_putstr_fd("Incorrect scene filename\n", 2);
	   return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	   return (error_open_file(filename));
	str = get_next_line(fd);
	while (str)
	{
		(void) str;
		free(str);
		str = get_next_line(fd);
	}
	
	return (NULL);
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

t_camera	*create_camera(t_coord *vp, t_coord *vector, int fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (! camera)
		exit_error("malloc error in create_camera");
	camera->view_point = vp;
	camera->vector = vector;
	camera->FOV = fov;
	
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
