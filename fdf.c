/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:14:23 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/22 10:37:20 by jetownle         ###   ########.fr       */
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

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		perror("error mallocing fdf struct");
	gnlread = ft_read(fd);
	fdf->map.height = count_lines(fdf, fd);
	if(!(fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height)))
		perror("error mallocing values");
	value_atoi(fdf, fd);
	fdf->mlx.win = mlx_init();
	fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT, "42");
	reset(&fdf);
	mlx_expose_hook(fdf->mlx.win, render, fdf);
	mlx_key_hook(fdf->mlx.win, keys);
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
	mlx_pixel_put(mlx->init, mlx->win, t_map->x1, t_map->y1, 0xFFFFFF);
	e = (2 * t_map->dy) - t_map->dx;
	inc1 = 2 * (t_map->dy - t_map->dx);
	inc2 = 2 * t_map->dy;
	while (i < t_map->dx)
	{
		if (e >= 0)
		{
			t_map->y1 = t_map->y1 + t_map->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		t_map->x1 = t_map->x1 + t_map->incx;
		mlx_pixel_put(mlx->init, mlx->win, t_map->x1, t_map->y1, 0xFFFFFF);
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
	mlx_pixel_put(mlx->init, mlx->win, t_map->x1, t_map->y1, 0xFFFFFF);
	e = (2 * t_map->dx) - t_map->dy;
	inc1 = 2 * (t_map->dx - t_map->dy);
	inc2 = 2 * t_map->dx;
	while (i < fdf->dy)
	{
		if (e >= 0)
		{
			t_map->x1 = t_map->x1 + t_map->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		t_map->y1 = t_map->y1 + t_map->incy;
		mlx_pixel_put(mlx->init, mlx->win, t_map->x1, t_map->y1, 0xFFFFFF);
		i++;
	}
}

void	reset(t_fdf *fdf)
{
	fdf->scalx = 24;
	fdf->scaly = 42;
	fdf->startx = 666;
	fdf->starty = 33;
}

