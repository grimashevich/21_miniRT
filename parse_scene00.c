/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/23 16:28:42 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*get_file_name(char *str);
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
void			free_scene(t_scene *scene);
t_scene			*create_scene(void);
int				open_scene_file(char *filename, int *fd);
int				check_scene_file_extension(char *filename);

int	parse_error(int line_num, char *str)
{
	char	*line_num_str;
	ft_putstr_fd("Parsing error in line ", 2);
	line_num_str = ft_itoa(line_num);
	if (line_num_str == NULL)
		exit_error("malloc error in parse_error");
	ft_putstr_fd(line_num_str, 2);
	free(line_num_str);
	ft_putstr_fd(". ", 2);
	ft_putstr_fd(str, 2);
	return (1);
}

int	add_alight_to_scene(t_scene *scene, char *str, int line_num)
{
	if (scene->alight)
	{
		//free(str);
		return (parse_error(line_num, "There is second ambient light in scene."));
	}
	scene->alight = parse_alight(str);
	//free(str);
	if (scene->alight == NULL)
		return (parse_error(line_num, "Ambient light parse error"));
	return (0);	
}

int	get_light_count(t_light	**lights)
{
	int	i;

	if (lights == NULL)
		return (0);
	i = 0;
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
		//free(str);
		return (parse_error(line_num, "There is second light in scene."));
	}
	add_light_to_array(&(scene->lights), parse_light(str));
	//free(str);
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
	//free(str);
	if (scene->camera == NULL)
		return (parse_error(line_num, "Camera parse error"));
	return (0);
}

int	get_object_count(t_object	**object_array)
{
	int	i;

	if (object_array == NULL)
		return (0);
	i = 0;
	while (object_array[i])
		i++;
	return (i);	
}

void add_object_to_array(t_object ***object_array, t_object *new_object)
{
	t_object	**old_obj_array;
	t_object	**new_obj_array;
	int			i;

	old_obj_array = *object_array;
	new_obj_array = malloc(sizeof(t_object *) * (get_object_count(old_obj_array) +2));
	if (! new_obj_array)
		exit_error("malloc error in add_object_to_array");
	i = 0;
	while (old_obj_array && old_obj_array[i])
	{
		new_obj_array[i] = old_obj_array[i];
		i++;
	}
	new_obj_array[i++] = new_object;
	new_obj_array[i] = NULL;
	free(old_obj_array);
	*object_array = new_obj_array;
}


t_object	*parse_sphere(char *str);
t_object	*parse_plane(char *str);
t_object	*parse_cylinder(char *str);

int	add_object_to_scene(t_scene *scene, char *str, int line_num)
{
	t_object	*new_object;

	if (str[0] == 's')
		new_object = parse_sphere(str);
	else if (str[0] == 'p')
		new_object = parse_plane(str);
	else if (str[0] == 'c')
		new_object = parse_cylinder(str);
	else
		return (parse_error(line_num, "Wrong object indetifier"));
	if (new_object == NULL)
		return (parse_error(line_num, "Object parse error. "));
	add_object_to_array(&(scene->objects), new_object);
	//free(str);
	return (0);
}

int	is_object_in_str(char *str)
{
	if (! (str[0] != 's' || str[0] != 'p' || str[0] != 'c'))
		return (0);
	if (! (str[1] != 'p' || str[1] != 'l' || str[1] != 'y'))
		return (0);
	if (! ft_is_spc(str[2]))
		return (0);
	return (1);
}

int	parse_str_scene(t_scene *scene, char *str, int line_num)
{
	int	add_error;

	str = ft_strtrim(str, " \t\n");
	if (str[0] == 0)
		add_error = 0;
	else if (str[0] == 'A' && ft_is_spc(str[1]))
		add_error = add_alight_to_scene(scene, str, line_num);
	else if (str[0] == 'C' && ft_is_spc(str[1]))
		add_error = add_camera_to_scene(scene, str, line_num);
	else if (str[0] == 'L' && ft_is_spc(str[1]))
		add_error = add_light_to_scene(scene, str, line_num);
	else if (is_object_in_str(str))
		add_error = add_object_to_scene(scene, str, line_num);
	else
		add_error = 1;
	free(str);
	if (add_error != 0)
	{
		free_scene(scene);
		return (1);
	}
	return (add_error);
}

t_scene	*create_scene(void)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (scene == NULL)
		exit_error("malloc error in create_scene");
	return (scene);
}

int	open_scene_file(char *filename, int *fd)
{
	if (check_scene_file_extension(filename) == 0)
	{
	   ft_putstr_fd("Incorrect scene filename\n", 2);
	   return (0);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	   return (0);
	return (1);
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
