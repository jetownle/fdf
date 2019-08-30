/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:29:55 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/28 15:49:13 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "unistd.h"
#include "fcntl.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

# define WIN_WIDTH					(1920)
# define WIN_HEIGHT					(1080)
# define KEY_ESCAPE			 		(0X35)

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*image;
	void	*ptr;
}				t_mlx;

typedef struct s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct s_map
{
	int		**values;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		incx;
	int		incy;
	int		i;
	int		j;
	int		k;
	int		width;
	int		height;
	int		startx;
	int		starty;
	int		scalx;
	int		scaly;
}				t_map;

typedef	struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
}				t_fdf;

int		main(int argc, char **argv);
int		fdf(int fd, char **argv);
int exit_key(int keycode, void *param);
int		render(t_fdf *fdf);

/* 
** Read functs
*/
char	**ft_read(t_fdf *fdf,int fd, char **argv);
void value_atoi(t_fdf *fdf, char **argv);
void value_splatoi(t_fdf *fdf, int y, int z, char *line);
int value_count(char *line);
void	draw_vertical(t_fdf *fdf);
void	draw_horizontal(t_fdf *fdf);
void 	bh_dispatch(t_fdf *fdf);
void	m_neg(t_fdf *fdf);
void	m_pos(t_fdf *fdf);
void	init(t_fdf *fdf);

#endif
