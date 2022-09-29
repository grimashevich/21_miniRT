/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:00:26 by eclown            #+#    #+#             */
/*   Updated: 2022/09/29 20:15:45 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		*parse_color(char *str);
t_color		*parse_coord(char *str);
t_light		*parse_light(char *str);
t_camera	*parse_camera(char *str);
t_scene		*parse_scene(char *filename);
void		remove_dbl_space(char **str);
char		*get_file_name(char *str);

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_scr	*scr_init(void)
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
	t_scene	*sc;

	sc = parse_scene("test.rt");
	(void) sc;
	free_scene(sc);
}

int	main(int argc, char *argv[])
{
	sandbox();
	return (0);
}
