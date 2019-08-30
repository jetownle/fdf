/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/28 17:53:56 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	if (z > 30000)
		z = 30000;
	if (z < -30000)
		z = -30000;
	return (fdf->map.starty + ((fdf->map.scaly) * x) \
		   	+ ((fdf->map.scaly) * y) - (z * 2));
}

void	draw_vertical(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < (fdf->map.width - 1))
		{
			fdf->map.x1 = fdf->map.startx - (fdf->map.scalx * y) \
						+ (fdf->map.scalx * x);
			fdf->map.y1 = coord_y(fdf, x, y, fdf->map.values[y][x]);
			x++;
			fdf->map.x2 = fdf->map.startx - (fdf->map.scalx * y) \
						+ (fdf->map.scalx * x);
			fdf->map.y2 = coord_y(fdf, x, y, fdf->map.values[y][x]);
			bh_dispatch(fdf);
		}
		y++;
	}
}

void	draw_horizontal(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < (fdf->map.height - 1))
	{
		x = 0;
		while (x < fdf->map.width && (fdf->map.width + 1 - x) > 0)
		{
			fdf->map.x1 = fdf->map.startx - (fdf->map.scalx * y) \
						+ (fdf->map.scalx * x);
			fdf->map.y1 = coord_y(fdf, x, y, fdf->map.values[y][x]);
			fdf->map.x2 = fdf->map.startx - (fdf->map.scalx * (y + 1)) \
						+ (fdf->map.scalx * x);
			fdf->map.y2 = coord_y(fdf, x, y + 1, fdf->map.values[y + 1][x]);
			bh_dispatch(fdf);
			x++;
		}
	}
}

void bh_dispatch(t_fdf *fdf)
{
	fdf->map.dx = fdf->map.x2 - fdf->map.x1;
	fdf->map.dy = fdf->map.y2 - fdf->map.y1;
	fdf->map.dx = abs(fdf->map.dx);
	fdf->map.dy = abs(fdf->map.dy);
	fdf->map.incx = (fdf->map.x2 > fdf->map.x1) ? 1 : -1;
	fdf->map.incy = (fdf->map.y2 > fdf->map.y1) ? 1 : -1;
	if (fdf->map.dx > fdf->map.dy)
		m_neg(fdf);
	else
		m_pos(fdf);
}


int		render(t_fdf *fdf)
{
	draw_vertical(fdf);
	draw_horizontal(fdf);
	return (1);
}

int exit_key(int keycode, void *param)
{
	param = 0;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

