/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:00:26 by eclown            #+#    #+#             */
/*   Updated: 2022/09/29 20:18:26 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "scene_converter.h"

void change_pointer(void **old, void *new);
t_minirt	*convert_scene(t_minirt_p *in);

t_alight *convert_alight(t_alight_p *obj_in);


void	sandbox(void)
{
	t_minirt	*scene;

	scene = parse_scene("test.rt");
	(void ) scene;
	free_scene(scene);
	printf("Done\n");
}

int	main(void)
{
	sandbox();
	return (0);
}
