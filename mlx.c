/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/09/04 01:34:48 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	return (fdf->startx - (fdf->scalx * y) + (fdf->scalx * x));
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
	return (fdf->starty + ((fdf->scaly) * x) \
		   	+ ((fdf->scaly) * y) - (z * 2));
}

void	draw_vertical(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < (fdf->width - 1))
		{
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->values[i][j]);
			j++;
			fdf->x2 = coord_x(fdf, j, i);
			fdf->y2 = coord_y(fdf, j, i, fdf->values[i][j]);
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
	while (i < (fdf->height - 1))
	{
		j = 0;
		while (j < fdf->width && (fdf->width + 1 - j) > 0)
		{
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->values[i][j]);
			fdf->x2 = coord_x(fdf, j, i + 1);
			fdf->y2 = coord_y(fdf, j, i + 1, fdf->values[i + 1][j]);
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

