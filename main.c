/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:09 by eclown            #+#    #+#             */
/*   Updated: 2022/01/29 22:25:20 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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


double	ft_atod(char *str)
{
/* 	double	result;
	int		part1;
	int		part2; */
	char	**splits;

	splits = ft_split_new(str, '.');
	return (1.2);
	
}


void	sandbox()
{
	ft_atod("12....25");
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
