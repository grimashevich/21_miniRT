/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:38 by eclown            #+#    #+#             */
/*   Updated: 2022/08/30 19:01:01 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include	"libft/libft.h"
# include	<stddef.h>
# include	<stdarg.h>
# include	<stdio.h>
# include	<sys/fcntl.h>
# include	"mlx/mlx.h"
# include	"mlx/mlx_png.h"

typedef struct s_scr {
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
}	t_scr;

enum obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_TRGB
{
	int transp;
	int R;
	int G;
	int B;
}   t_TRGB;

typedef struct s_coord
{
	double  x;
	double  y;
	double  z;
}   t_coord;

typedef struct s_alight
{
	double  ratio;
	t_TRGB  color;
}   t_alight;


typedef struct s_camera
{
	t_coord		 	view_point;
	t_coord		 	vector;
	unsigned int	FOV;
}   t_camera;


typedef struct s_light
{
	t_coord		 	light_point;
	t_coord		 	brightness;
	t_TRGB 			color;
}   t_light;


typedef struct s_object
{
	enum obj_type	type;
	t_coord		 	coord;
	t_TRGB 			color;
	void			*data;
}   t_object;

typedef struct s_scene //TODO Check it
{
	char		*description;
	t_alight	alight;
	t_camera	camera;
	t_light	    *lights;
	t_object	*objects;
}	t_scene;


char	**ft_split_new(char *str, char sep);
int		text_len(char **text);
void	free_text(char **text);
int		ft_num_len(int n);
double	ft_atod(char *str);
float	ft_atof(char *str);

#endif