/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:00:26 by eclown            #+#    #+#             */
/*   Updated: 2022/09/24 19:10:27 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*parse_color(char *str);
t_color	*parse_coord(char *str);
t_light	*parse_light(char *str);
t_camera	*parse_camera(char *str);
t_scene *parse_scene(char *filename);

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

void	remove_dbl_space(char **str);
char	*get_file_name(char *str);

void	sandbox(void)
{	
/*	char *str = ft_strdup("../folder/test.rt");
	remove_dbl_space(&str);
	char *fname = get_file_name(str);
	printf("%s\n", fname);
	return;*/
	
 	t_scene *sc = parse_scene("test.rt");
	(void) sc;
	free_scene(sc);
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
