/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/26 14:18:22 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			fdf->map.y1 = fdf->map.starty + ((fdf->map.scaly) * x) \
					   	+ ((fdf->map.scaly) * y) - (fdf->map.values[y][x] * 2);
			x++;
			fdf->map.x2 = fdf->map.startx - (fdf->map.scalx * y) \
						+ (fdf->map.scalx * x);
			fdf->map.y2 = fdf->map.starty + ((fdf->map.scaly) * x) \
						+ ((fdf->map.scaly) * y) - (fdf->map.values[y][x] * 2);
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
			fdf->map.y1 = fdf->map.starty + ((fdf->map.scaly) * x) \
					   	+ ((fdf->map.scaly) * y) - (fdf->map.values[y][x] * 2);
			fdf->map.x2 = fdf->map.startx - (fdf->map.scalx * y) \
						+ (fdf->map.scalx * x);
			fdf->map.y2 = fdf->map.starty + ((fdf->map.scaly) * x) \
						+ ((fdf->map.scaly) * y) - (fdf->map.values[y + 1][x] * 2);
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


/*  fdf->mlx.image = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.image, &fdf->image.bpp, \
			&fdf->image.size, &fdf->image.endian);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.image);
	return (0);
 */
