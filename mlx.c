/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/30 17:40:31 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int y, int x)
{
	return (fdf->map.startx - (fdf->map.scalx * x) + (fdf->map.scalx * y));
}

int		coord_y(t_fdf *fdf, int y, int x, int z)
{
	if (z > 30000)
	{
		z = 30000;
	}
	if (z < -30000)
	{
		z = -30000;
	}
	return (fdf->map.starty + ((fdf->map.scaly) * y) \
		   	+ ((fdf->map.scaly) * x) - (z * 2));
}

void	draw_vertical(t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	while (x < fdf->map.height)
	{
		y = 0;
		while (y < (fdf->map.width - 1))
		{
			fdf->map.x1 = coord_x(fdf, y, x);
			fdf->map.y1 = coord_y(fdf, y, x, fdf->map.values[x][y]);
			y++;
			fdf->map.x2 = coord_x(fdf, y, x);
			fdf->map.y2 = coord_y(fdf, y, x, fdf->map.values[x][y]);
			bh_dispatch(fdf);
		}
		x++;
	}
}

void	draw_horizontal(t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	while (x < (fdf->map.height - 1))
	{
		y = 0;
		while (y < fdf->map.width && (fdf->map.width + 1 - y) > 0)
		{
			fdf->map.x1 = coord_x(fdf, y, x);
			fdf->map.y1 = coord_y(fdf, y, x, fdf->map.values[x][y]);
			fdf->map.x2 = coord_x(fdf, y, x + 1);
			fdf->map.y2 = coord_y(fdf, y, x + 1, fdf->map.values[x + 1][y]);
			bh_dispatch(fdf);
			y++;
		}
		x++;
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

