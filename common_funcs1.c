/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_funcs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:00:18 by eclown            #+#    #+#             */
/*   Updated: 2022/08/30 19:00:20 by eclown           ###   ########.fr       */
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
	int		part2;
	double	mp;
	char	**splits;

	splits = ft_split_new(str, '.');
	if (text_len(splits) > 2)
	{
		free_text(splits);
		return (0);
	}
	part1 = ft_atoi(splits[0]);
	if (text_len(splits) == 2)
		part2 = ft_atoi(splits[1]);
	else
		part2 = 0;
	mp = (double) part2 / ft_ipow(10, ft_strlen(splits[1]));
	result = (double) part1 + mp;
	free_text(splits);
	return (result);
}
