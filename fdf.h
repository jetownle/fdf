/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:29:55 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/13 04:28:51 by jetownle         ###   ########.fr       */
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

# define WIN_WIDTH		(1280)
# define WIN_HEIGHT		(720)

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
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
	float	x;
	float	y;
	float	z;
	int		width;
	int		height;
}				t_map;

typedef	struct	s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
}				t_fdf;

int		main(int argc, char **argv);
int		fdf(int fd);
char	**ft_read(int fd);

#endif
