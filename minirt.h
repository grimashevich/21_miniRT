/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/29 20:09:17 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef IS_BONUS
#  define IS_BONUS_PART 1
# endif

# include	"libft/libft.h"
# include	<stddef.h>
# include	<stdarg.h>
# include	<stdio.h>
# include	<sys/fcntl.h>
# include	"mlx/mlx.h"
# include	"mlx/mlx_png.h"
# include	"get_next_line.h"


typedef struct s_scr {
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
}	t_scr;

enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_color
{
	int	transp;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_alight_p
{
	float	ratio;
	t_color	*color;
}	t_alight_p;

typedef struct s_camera_p
{
	t_vec			*orig;
	t_vec			*dir;
	unsigned int	fov;
	t_vec			right;
	t_vec			up;
}	t_camera_p;

typedef struct s_light_p
{
	t_vec	*pos;
	double	intens;
	t_color	*color;
}	t_light_p;

typedef struct s_material_p
{
	t_color	*color;
	double	albedo[3];
	double	spec_exp;
}	t_material_p;

typedef struct s_object_p
{
	enum e_obj_type	type;
	t_material_p	*mat;
	void			*params;
}	t_object_p;

typedef struct s_sphere_data_p
{
	t_vec	*orig;
	double	r;
}	t_sphere_p;

typedef struct s_plane_data_p
{
	t_vec	*orig;
	t_vec	*normal;
}	t_plane_p;

typedef struct s_cylinder_data_p
{
	t_vec	*orig;
	t_vec	*dir;
	double	d;
	double	h;
}	t_cylinder_p;

typedef struct s_keys
{
	int	key_esc;
}	t_keys;

typedef struct s_ray
{
	t_vec	dir;
	t_vec	orig;
	double	t;
	t_vec	phit;
}	t_ray;

typedef struct s_scene
{
	char		*description;
	t_alight	*alight;
	t_camera	*camera;
	t_light		**lights;
	t_object	**objects;
	//t_mlx		*mlx;
	t_keys		*keys;
	t_ray		ray;
	double		tnear;
}	t_minirt;

void		exit_error(char *msg);
char		**ft_split_new(char *str, char sep);
int			text_len(char **text);
int			ft_is_spc(char c);
void		free_text(char **text);
int			ft_num_len(int n);
double		ft_atod(char *str);
float		ft_atof(char *str);
void		replace_space_chars_to_space(char *str);
void		free_text(char **text);
int			ft_is_integer(char *str);
int			ft_is_float(char *str);
int			is_all_float(char **text);
int			is_all_pos_int(char **text);
void		*file_format_error(char *str_err);
void		free_scene(t_minirt *scene);

/*typedef struct s_alight
{
	float	ratio;
	t_color	color;
}	t_alight;

typedef struct s_camera
{
	t_vec			orig;
	t_vec			dir;
	unsigned int	fov;
	t_vec			right;
	t_vec			up;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	double	intens;
	t_color	color;
}	t_light;

typedef struct s_material
{
	t_color	color;
	double	albedo[3];
	double	spec_exp;
}	t_material;

typedef struct s_object
{
	enum e_obj_type	type;
	t_material		mat;
	void			*params;
	int				(*intersect)();
	t_vec			(*get_normal)();
}	t_object;

typedef struct s_sphere_data
{
	t_vec	orig;
	double	r;
}	t_sphere;

typedef struct s_plane_data
{
	t_vec	orig;
	t_vec	normal;
}	t_plane;

typedef struct s_cylinder_data
{
	t_vec	orig;
	t_vec	dir;
	double	d;
	double	h;
}	t_cylinder;*/

#endif	//MINIRT_H