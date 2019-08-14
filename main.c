/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:05:34 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/13 04:13:40 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fdf(fd) == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}

