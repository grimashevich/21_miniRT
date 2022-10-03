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
	t_minirt_p	*scene_p;
	t_minirt	*scene;
	t_alight *al = convert_alight(NULL);

	(void) scene_p;
	(void ) al;
	scene_p = parse_scene_p("test.rt");
	scene = convert_scene(scene_p);
	free_scene_p(scene_p);
	(void ) scene;

}

int	main(void)
{
	sandbox();
	return (0);
}
