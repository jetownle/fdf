/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:14:23 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/21 08:48:52 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
** core of the program, calls most of the functions, makes the struct of structs
*/

int			fdf(int fd)
{
	t_fdf	*fdf;
	char	**gnlread;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	gnlread = ft_read(fd);
	fdf->map.height = count_lines(fdf, fd);
	fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height);
	mapatoi(fdf, fd);
	fdf->mlx.win = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, "42");
	//	mlx_key_hook(fdf->mlx.init, keys);
	// mlx_loop_hook(fdf->mlx.init, render, fdf);
	// mlx_loop(fdf->mlx.init);

	return (0);
}

