/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:00:26 by eclown            #+#    #+#             */
/*   Updated: 2022/09/13 18:20:32 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_TRGB	*parse_color(char *str);
t_TRGB	*parse_coord(char *str);
t_light	*parse_light(char *str);
t_camera	*parse_camera(char *str);

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_scr *scr_init()
{
	t_scr	*screen;

	screen = malloc(sizeof(t_scr));
	if (! screen)
		return (NULL);
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, 1024,
			768, "miniRT");
	return (screen);
}

void	sandbox(void)
{
	t_camera *camera = parse_camera("C -50.0,0,20 0,0,1 0");
	(void) camera;
	
/* 	t_light *light = parse_light("L -40.0,50.0,0.0 0.6 10,0,255");
	(void) light; */
/* 	t_alight *alight1 = parse_light("A .5 255,255,255");
	t_alight *alight2 = parse_light("A 0.2 255,255,255");
	t_alight *alight3 = parse_light("A 0.2 255,255,255");
	t_alight *alight4 = parse_light("A 0.2 255,255,255");
	t_alight *alight5 = parse_light("A 0.2 255,255,255");
	t_alight *alight6 = parse_light("A 0.2 255,255,255");
	(void) alight1;
	(void) alight2;
	(void) alight3;
	(void) alight4;
	(void) alight5;
	(void) alight6; */
	return;
}


int	main(int argc, char *argv[])
{

	sandbox();
	return (0);

	(void) argc;
	(void) argv;
	
	t_scr	*screen;

	screen = scr_init();
	// mlx_hook(map->win, 2, (1L << 0), key_hook, map);
	// mlx_hook(map->win, 17, 0L, exit_game, NULL);
	int x = 300;
	int y = 300;

	while (x < 400)
	{
		while (y < 400)
		{
			mlx_pixel_put(screen->mlx, screen->win, x, y, get_trgb(128, 255, 0, 0));
			y++;
		}
		y = 300;
		x++;
	}
	
	mlx_loop(screen->mlx);
}
