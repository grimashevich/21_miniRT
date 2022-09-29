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

t_scene		*parse_scene(char *filename);

void	sandbox(void)
{	
	t_scene	*sc;

	(void) sc;
	sc = parse_scene("test.rt");
	free_scene(sc);
}

int	main(void)
{
	sandbox();
	return (0);
}
