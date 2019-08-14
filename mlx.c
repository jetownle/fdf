/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/14 07:18:52 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		render(t_fdf *fdf)
{

	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
			&fdf->image.size, &fdf->image.endian);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.image);
}

static int keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

