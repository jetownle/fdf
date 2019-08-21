/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 03:46:58 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/20 02:55:16 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		render(t_fdf *fdf)
{

	fdf->mlx.image = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.image, &fdf->image.bpp, \
			&fdf->image.size, &fdf->image.endian);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.image);
	return (0);
}
/*
static int keys(int keycode)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

*/
