/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:14:23 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/28 15:53:21 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
** core of the program, calls most of the functions, makes the struct of structs
*/

int			fdf(int fd, char **argv)
{
	t_fdf	*fdf;
	char	**gnlread;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		perror("error mallocing fdf struct");
	fdf->mlx.init = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, "42");
	init(fdf);
	gnlread = ft_read(fdf, fd, argv);
	mlx_expose_hook(fdf->mlx.win, render, &fdf);
	mlx_key_hook(fdf->mlx.win, exit_key, &fdf);
	mlx_loop(fdf->mlx.init);

	return (0);
}

void	m_neg(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, fdf->map.x1, fdf->map.y1, 0xFFFFFF);
	e = (2 * fdf->map.dy) - fdf->map.dx;
	inc1 = 2 * (fdf->map.dy - fdf->map.dx);
	inc2 = 2 * fdf->map.dy;
	while (i < fdf->map.dx)
	{
		if (e >= 0)
		{
			fdf->map.y1 = fdf->map.y1 + fdf->map.incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->map.x1 = fdf->map.x1 + fdf->map.incx;
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, fdf->map.x1, fdf->map.y1, 0xFFFFFF);
		i++;
	}
}

void	m_pos(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, fdf->map.x1, fdf->map.y1, 0xFFFFFF);
	e = (2 * fdf->map.dx) - fdf->map.dy;
	inc1 = 2 * (fdf->map.dx - fdf->map.dy);
	inc2 = 2 * fdf->map.dx;
	while (i < fdf->map.dy)
	{
		if (e >= 0)
		{
			fdf->map.x1 = fdf->map.x1 + fdf->map.incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->map.y1 = fdf->map.y1 + fdf->map.incy;
		mlx_pixel_put(fdf->mlx.init, fdf->mlx.win, fdf->map.x1, fdf->map.y1, 0xFFFFFF);
		i++;
	}
}

void	init(t_fdf *fdf)
{
	fdf->map.scalx = 20;
	fdf->map.scaly = 20;
	fdf->map.startx = 850;
	fdf->map.starty = 50;
}

