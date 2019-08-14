/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:14:23 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/14 05:17:45 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf(int fd)
{
	t_fdf	*fdf;
	char	**gnlread;
	char	title[14];

	title = "Jeremy was here";
	gnlread = ft_read(fd);
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, title);
	mlx_key_hook(fdf->mlx.init, keys, fdf);
	mlx_loop_hook(fdf->mlx.init, render, fdf);
	mlx_loop(fdf->mlx.init);

	return (0);
}

