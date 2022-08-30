/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:36:48 by EClown            #+#    #+#             */
/*   Updated: 2022/08/30 20:11:00 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <stddef.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include "minirt.h"

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

typedef struct scene
{
	char		*description;
	t_alight	alight;
	t_camera	camera;
	t_light	    *lights;
	t_object	*objects;
};



char			*get_next_line(int fd);
char			*ft_strjoin2(char *s1, char *s2, char *nl);

#endif