/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene11.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:14:06 by eclown            #+#    #+#             */
/*   Updated: 2022/09/24 19:02:03 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_scene_file_extension(char *filename);

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
