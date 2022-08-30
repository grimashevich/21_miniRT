/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EClown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:36:48 by EClown            #+#    #+#             */
/*   Updated: 2022/01/29 21:23:58 by EClown           ###   ########.fr       */
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
# include "so_long.h"

char			*get_next_line(int fd);
char			*ft_strjoin2(char *s1, char *s2, char *nl);

#endif