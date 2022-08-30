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

#include "so_long.h"

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

void	*free_and_return_null(void *p)
{
	free(p);
	return (NULL);
}

void	free_array(char **p, int n)
{
	while (n > 0)
		free(p[--n]);
}

void	*close_file_return_null(int fd)
{
	close(fd);
	return (NULL);
}
