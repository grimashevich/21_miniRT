/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/13 19:30:26 by eclown           ###   ########.fr       */
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
# include	"get_next_line.h"
#include	"limits.h"

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
	float  ratio;
	t_TRGB  *color;
}   t_alight;

typedef struct s_camera
{
	t_coord		 	*view_point;
	t_coord		 	*vector;
	unsigned int	FOV;
}   t_camera;

typedef struct s_light
{
	t_coord		 	*light_point;
	float		 	brightness;
	t_TRGB 			*color;
}   t_light;

typedef struct s_object
{
	enum obj_type	type;
	t_coord		 	*coord;
	t_TRGB 			*color;
	void			*data;
}   t_object;

typedef struct s_sphere_data
{
	float	diameter;
	//TODO pointer to calc function	
}   t_sphere_data;

typedef struct s_plane_data
{
	t_coord	*vector;
	//TODO pointer to calc function	
}   t_plane_data;

typedef struct s_cylinder_data
{
	float	diameter;
	float	height;
	t_coord	*vector;
	//TODO pointer to calc function	
}   t_cylinder_data;

typedef struct s_scene
{
	char		*description;
	t_alight	alight;
	t_camera	camera;
	t_light	    **lights;
	t_object	**objects;
}	t_scene;

void		exit_error(char *msg);
char		**ft_split_new(char *str, char sep);
int			text_len(char **text);
void		free_text(char **text);
int			ft_num_len(int n);
double		ft_atod(char *str);
float		ft_atof(char *str);
void		replace_space_chars_to_space(char *str);
void		free_text(char **text);
int			ft_is_integer(char *str);
int 		ft_is_float(char *str);
int			is_all_float(char **text);
int			is_all_pos_int (char **text);
t_alight	*parse_alight(char *str);
void		*file_format_error(char *str_err);

#endif