/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_funcs0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:32:58 by eclown            #+#    #+#             */
/*   Updated: 2022/01/29 21:22:40 by EClown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_trim_str(char *s1, char const *set)
{
	char	*result;

	if (! s1)
		return (NULL);
	result = ft_strtrim(s1, set);
	if (result == s1)
		return (s1);
	free(s1);
	return (result);
}

int	text_len(char **text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		i++;
	}
	return (i);
}

void	free_text(char **text)
{
	int	i;

	if (! text)
		return ;
	i = 0;
	while (text[i])
	{
		free(text[i++]);
	}
	free(text);
}
