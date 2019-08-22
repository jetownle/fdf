/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/22 10:33:33 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vertical(t_fdf *fdf)
{
	int j;

	while (i < t_map->height)
	{
		j = 0;
		while (j < (t_map->width - 1))
		{
			t_map->x1 = t_map->startx - (t_map->scalx * y) \
						+ (t_map->scalx * x);
			t_map->y1 = t_map->starty + ((t_map->scaly) * x) \
					   	+ ((t_map->scaly) * y) - (t_map->values[i][j] * 2);
			j++;
			t_map->x2 = t_map->startx - (t_map->scalx * y) \
						+ (t_map->scalx * x);
			t_map->y2 = t_map->starty + ((t_map->scaly) * x) \
						+ ((t_map->scaly) * y) - (t_map->values[i][j] * 2);
			bh_dispatch(fdf);
		}
	}
}

void	draw_horizontal(t_fdf *fdf)
{
	int j;

	while (i < (t_map->height - 1))
	{
		j = 0;
		while (j < t_map->width && (t_map->width + 1 - j) > 0)
		{
			t_map->x1 = t_map->startx - (t_map->scalx * y) \
						+ (t_map->scalx * x);
			t_map->y1 = t_map->starty + ((t_map->scaly) * x) \
					   	+ ((t_map->scaly) * y) - (t_map->values[i][j] * 2);
			t_map->x2 = t_map->startx - (t_map->scalx * y) \
						+ (t_map->scalx * x);
			t_map->y2 = t_map->starty + ((t_map->scaly) * x) \
						+ ((t_map->scaly) * y) - (t_map->values[i + 1][j] * 2);
			bh_dispatch(fdf);
			j++;
		}
	}
}

void bh_dispatch(t_fdf *fdf)
{
	t_map->dx = t_map->x2 - t_map->x1;
	t_map->dy = t_map->y2 - t_map->y1;
	t_map->dx = abs(t_map->dx);
	t_map->dy = abs(t_map->dy);
	t_map->incx = (t_map->x2 > t_map->x1 ? 1 : -1;
	t_map->incy = (t_map->y2 > t_map->y1 ? 1 : -1;
	if (t_map->dx > t_map->dy)
		m_neg(fdf);
	else
		m_pos(fdf);
}


int		render(t_fdf *fdf)
{
	draw_vertical(fdf);
	draw_horizontal(fdf);
}

int exit_key(int keycode)
{
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
