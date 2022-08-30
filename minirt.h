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


char	**ft_split_new(char *str, char sep);
int		text_len(char **text);
void	free_text(char **text);
int		ft_num_len(int n);
double	ft_atod(char *str);

#endif