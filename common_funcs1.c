/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_funcs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:00:18 by eclown            #+#    #+#             */
/*   Updated: 2022/08/30 19:03:47 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

int	ft_ipow(int base, int pow)
{
	int	tmp;

	tmp = base;
	while (pow > 1)
	{
		base = base * tmp;
		pow--;
	}
	return (base);
}


double	ft_atod(char *str)
{
 	double	result;
	int		part1;
	double	part2;
	char	**splits;

	splits = ft_split_new(str, '.');
	if (text_len(splits) > 2)
	{
		free_text(splits);
		return (0);
	}
	part1 = ft_atoi(splits[0]);
	if (text_len(splits) == 2)
	{
		part2 = ft_atoi(splits[1]);
		part2 =  part2 / ft_ipow(10, ft_strlen(splits[1]));
	}
	else
		part2 = 0;
	result = (double) part1 + part2;
	free_text(splits);
	return (result);
}

float	ft_atof(char *str)
{
 	float	result;
	int		part1;
	float	part2;
	char	**splits;

	splits = ft_split_new(str, '.');
	if (text_len(splits) > 2)
	{
		free_text(splits);
		return (0);
	}
	part1 = ft_atoi(splits[0]);
	if (text_len(splits) == 2)
	{
		part2 = ft_atoi(splits[1]);
		part2 =  part2 / (float) ft_ipow(10, ft_strlen(splits[1]));
	}
	else
		part2 = 0;
	result = (float) part1 + part2;
	free_text(splits);
	return (result);
}
