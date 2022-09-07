/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclown <eclown@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:26:52 by eclown            #+#    #+#             */
/*   Updated: 2022/09/07 19:16:32 by eclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int check_scene_file_extension(char *filename)
{
    int strlen = ft_strlen(filename);

    if (filename[strlen - 1] != 't' || filename[strlen - 2] != 'r')
        return (0);
    if (filename[strlen - 3] != '.')
        return (0);
    return (1);
}

void add_light_to_array(t_light ***array)
{
    t_light **new_array;
    int     array_len;
    int     i;

    i = 0;
    while (//TODO HERE)
    {
        /* code */
    }
        
}

t_scene *parse_t_scene(char *filename)
{
    int fd;

    if (check_scene_file_extension(filename) == 0)
    {
        ft_putstr_fd("Incorrect scene filename\n", 2);
        return (NULL);
    }
    fd = open(filename, "O_RDONLY");
    if (fd == -1)
    {
        ft_putstr_fd("Error open file ", 2);
        ft_putstr_fd(filename, 2);
        ft_putstr_fd("'n", 2);
        return (NULL);
    }
}
