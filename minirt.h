/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:33:38 by eclown            #+#    #+#             */
/*   Updated: 2022/01/29 23:12:07 by EClown           ###   ########.fr       */
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

#endif