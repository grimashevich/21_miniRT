/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:38 by eclown            #+#    #+#             */
/*   Updated: 2022/09/26 20:07:39 by eclown           ###   ########.fr       */
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

typedef struct s_trgb
{
	int	transp;
	int	r;
	int	g;
	int	b;
}	t_trgb;
//! поменять название на t_color

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;
//! поменять название на t_vec

typedef struct s_alight
{
	float	ratio;
	t_trgb	*color;
}	t_alight;

typedef struct s_camera
{
	t_coord			*view_point;//orig OK
	t_coord			*vector;//dir
	unsigned int	fov;
}	t_camera;
//! добавить поля в t_camera
	//t_vec	right;
	//t_vec	up;
	//переименовать поля

typedef struct s_light
{
	t_coord	*light_point;//pos
	float	brightness;//intens
	t_trgb	*color;
}	t_light;

typedef struct s_object
{
	enum e_obj_type	type;
	t_coord			*coord;
	t_trgb			*color;
	void			*data;
}	t_object;


//! изменить t_object
// перенести coord в data
// перенести color в material
//typedef struct	s_material
//{
	//t_color	color;
	//double	albedo[2];
	//double	spec_exp;
//}	t_material;


//! поменять структуры объектов на структуры ниже
//typedef struct	s_sphere
//{
	//t_vec	orig;
	//double	r;
//}	t_sphere;

//typedef struct	s_plane
//{
	//t_vec	orig;
	//t_vec	normal;
//}	t_plane;

//typedef struct	s_cylinder
//{
	//t_vec	orig;
	//t_vec	dir;
	//double	d;
	//double	h;
//}	t_cylinder;

typedef struct s_sphere_data
{
	float	diameter;
}	t_sphere_data;

typedef struct s_plane_data
{
	t_coord	*vector;	
}	t_plane_data;

typedef struct s_cylinder_data
{
	float	diameter;
	float	height;
	t_coord	*vector;	
}	t_cylinder_data;

typedef struct s_scene
{
	char		*description;
	t_alight	*alight;
	t_camera	*camera;
	t_light		**lights;
	t_object	**objects;
}	t_scene;

//! добавить недоюстающие поля
	//t_mlx		*mlx;
	//t_keys	*keys;
	//t_ray		ray;
	//double	tnear;
	//

	




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
void		free_scene(t_scene *scene);

#endif
