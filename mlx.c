/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/30 22:47:22 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	return (fdf->map.startx - (fdf->map.scalx * y) + (fdf->map.scalx * x));
}

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	if (z > 30000)
	{
		z = 30000;
	}
	if (z < -30000)
	{
		z = -30000;
	}
	return (fdf->map.starty + ((fdf->map.scaly) * x) \
		   	+ ((fdf->map.scaly) * y) - (z * 2));
}

void	draw_vertical(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < (fdf->map.width - 1))
		{
			fdf->map.x1 = coord_x(fdf, j, i);
			fdf->map.y1 = coord_y(fdf, j, i, fdf->map.values[i][j]);
			j++;
			fdf->map.x2 = coord_x(fdf, j, i);
			fdf->map.y2 = coord_y(fdf, j, i, fdf->map.values[i][j]);
			bh_dispatch(fdf);
		}
		i++;
	}
}

void	draw_horizontal(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < (fdf->map.height - 1))
	{
		j = 0;
		while (j < fdf->map.width && (fdf->map.width + 1 - j) > 0)
		{
			fdf->map.x1 = coord_x(fdf, j, i);
			fdf->map.y1 = coord_y(fdf, j, i, fdf->map.values[i][j]);
			fdf->map.x2 = coord_x(fdf, j, i + 1);
			fdf->map.y2 = coord_y(fdf, j, i + 1, fdf->map.values[i + 1][j]);
			bh_dispatch(fdf);
			j++;
		}
		i++;
	}
}

int		render(t_fdf *fdf)
{
	draw_vertical(fdf);
	draw_horizontal(fdf);
	return (1);
}

