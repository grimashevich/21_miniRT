/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/08 20:48:44 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* 
TODO
t_rgb create
t_coord create
 */
int check_scene_file_extension(char *filename)
{
	int strlen = ft_strlen(filename);

	if (filename[strlen - 1] != 't' || filename[strlen - 2] != 'r')
	   return (0);
	if (filename[strlen - 3] != '.')
	   return (0);
	return (1);
}

void add_light_to_array(t_light ***array, t_light *new_light)
{
	t_light **new_array;
	t_light **old_array;
	int	array_len;
	int	i;

	old_array = *array;
	i = 0;
	while (old_array[i])
	   i++;
	new_array = malloc(sizeof(t_light *) * (i + 2));
	if (! new_array)
		exit_error("malloc error in add_light_to_array");
	while (old_array[i])
	{
	   new_array[i] = old_array[i];
	   i++;
	}
	new_array[i++] = new_light;
	new_array[i] = NULL;
	i = 0;
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
	light->color = color;
	light->brightness = brightness;
	return (light);
}

t_scene *parse_t_scene(char *filename)
{
	int fd;

	if (check_scene_file_extension(filename) == 0)
	{
	   ft_putstr_fd("Incorrect scene filename\n", 2);
	   return (NULL);
	}
	fd = open(filename, "O_RDONLY");
	if (fd == -1)
	{
	   ft_putstr_fd("Error open file ", 2);
	   ft_putstr_fd(filename, 2);
	   ft_putstr_fd("'n", 2);
	   return (NULL);
	}
}
