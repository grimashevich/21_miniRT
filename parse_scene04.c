/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:07:06 by eclown            #+#    #+#             */
/*   Updated: 2022/09/12 20:50:49 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_TRGB	*parse_color(char *str);
t_coord	*parse_coord(char *str);

void	*file_format_error(char *str_err)
{
	ft_putstr_fd("Scene file format error: ", 2);
	ft_putstr_fd(str_err, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int check_alight_args(char **args)
{
	t_TRGB	*color;

	if (! ft_is_float(args[1]))
		return (0);
	if (text_len(args) != 3)
		return (0);
	color = parse_color(args[2]);
	if (color == NULL)
		return (0);
	free(color);
	return (1);
}

t_alight	*parse_alight(char *str)
{
	char		**bloks;
	t_alight	*alight;

	str = ft_strdup(str);
	replace_space_chars_to_space(str);
	bloks = ft_split_new(str, ' ');
	if (check_alight_args(bloks) == 0)
	{
		free_text(bloks);
		free(str);
		return (file_format_error("Ambient lightning wrong args"));
	}
	alight = malloc(sizeof(t_alight));
	if (! alight)
		exit_error("malloc error in parse_alight");
	alight->color = parse_color(bloks[2]);
	alight->ratio = ft_atof(bloks[1]);
	free_text(bloks);
	free(str);
	return (alight);
}

//TODO HERE parse_Camera