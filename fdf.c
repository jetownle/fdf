/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:14:23 by jetownle          #+#    #+#             */
/*   Updated: 2019/09/04 04:23:57 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bh_dispatch(t_fdf *fdf)
{
	fdf->dx = fdf->x2 - fdf->x1;
	fdf->dy = fdf->y2 - fdf->y1;
	fdf->dx = abs(fdf->dx);
	fdf->dy = abs(fdf->dy);
	fdf->incx = (fdf->x2 > fdf->x1) ? 1 : -1;
	fdf->incy = (fdf->y2 > fdf->y1) ? 1 : -1;
	if (fdf->dx > fdf->dy)
		m_neg(fdf);
	else
		m_pos(fdf);
}

void	m_neg(t_fdf *fdf)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->init, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
	e = (2 * fdf->dy) - fdf->dx;
	inc1 = 2 * (fdf->dy - fdf->dx);
	inc2 = 2 * fdf->dy;
	while (i < fdf->dx)
	{
		if (e >= 0)
		{
			fdf->y1 = fdf->y1 + fdf->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->x1 = fdf->x1 + fdf->incx;
		mlx_pixel_put(fdf->init, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
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
	mlx_pixel_put(fdf->init, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
	e = (2 * fdf->dx) - fdf->dy;
	inc1 = 2 * (fdf->dx - fdf->dy);
	inc2 = 2 * fdf->dx;
	while (i < fdf->dy)
	{
		if (e >= 0)
		{
			fdf->x1 = fdf->x1 + fdf->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		fdf->y1 = fdf->y1 + fdf->incy;
		mlx_pixel_put(fdf->init, fdf->win, fdf->x1, fdf->y1, 0xFFFFFF);
		i++;
	}
}

int		exit_key(int keycode, void *param)
{
	param = 0;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

/*
** core of the program, calls most of the functions,
** makes the struct of structs
*/

int		fdf(int fd, char **argv)
{
	t_fdf	fdf;
	char	**gnlread;

	init(&fdf);
	gnlread = ft_read(&fdf, fd, argv);
	fdf.init = mlx_init();
	fdf.win = mlx_new_window(fdf.init, WIN_WIDTH, WIN_HEIGHT, "42");
	mlx_expose_hook(fdf.win, render, &fdf);
	mlx_key_hook(fdf.win, exit_key, &fdf);
	mlx_loop(fdf.init);
	return (0);
}
