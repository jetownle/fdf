/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:29:55 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/14 05:38:56 by jetownle         ###   ########.fr       */
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

# define WIN_WIDTH					(1280)
# define WIN_HEIGHT					(720)
# define KEY_ANSI_A					(0X00)
# define KEY_ANSI_S					(0X01)
# define KEY_ANSI_D			 		(0X02)
# define KEY_ANSI_V			 		(0X09)
# define KEY_ANSI_B			 		(0X0B)
# define KEY_ANSI_Q			 		(0X0C)
# define KEY_ANSI_W			 		(0X0D)
# define KEY_ANSI_E			 		(0X0E)
# define KEY_ANSI_R			 		(0X0F)
# define KEY_ANSI_1			 		(0X12)
# define KEY_ANSI_2			 		(0X13)
# define KEY_ANSI_3			 		(0X14)
# define KEY_ANSI_4			 		(0X15)
# define KEY_ANSI_6			 		(0X16)
# define KEY_ANSI_5			 		(0X17)
# define KEY_ANSI_9			 		(0X19)
# define KEY_ANSI_7			 		(0X1A)
# define KEY_ANSI_8			 		(0X1C)
# define KEY_ANSI_0			 		(0X1D)
# define KEY_ANSI_J			 		(0X26)
# define KEY_ANSI_K			 		(0X28)
# define KEY_ANSI_N			 		(0X2D)
# define KEY_ANSI_M			 		(0X2E)
# define KEY_ESCAPE			 		(0X35)
# define KEY_LEFTARROW		  		(0X7B)
# define KEY_RIGHTARROW		 		(0X7C)
# define KEY_DOWNARROW		  		(0X7D)
# define KEY_UPARROW				(0X7E)


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