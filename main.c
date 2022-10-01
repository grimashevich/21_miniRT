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

t_alight *convert_alight(t_alight_p *obj_in);

t_minirt		*parse_scene(char *filename);

void	sandbox(void)
{	
	t_minirt	*sc;
	t_alight *al = convert_alight(NULL);

	(void) sc;
	(void ) al;
	sc = parse_scene("test.rt");
	free_scene(sc);

}

int	main(void)
{
	sandbox();
	return (0);
}
