/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 17:29:55 by jetownle          #+#    #+#             */
/*   Updated: 2019/09/04 04:42:40 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
# include "string.h"
# include "math.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx_macos/mlx.h"

# define WIN_WIDTH		(1920)
# define WIN_HEIGHT		(1080)
# define KEY_ESCAPE		(0X35)

typedef struct	s_fdf
{
	void		*init;
	void		*win;
	int			width;
	int			height;
	int			**values;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			startx;
	int			starty;
	int			incx;
	int			incy;
	int			scalx;
	int			scaly;
	int			j;
}				t_fdf;

int				main(int argc, char **argv);
int				fdf(int fd, char **argv);
char			**ft_read(t_fdf *fdf, int fd, char **argv);
void			init(t_fdf *fdf);
int				render(t_fdf *fdf);
int				exit_key(int keycode, void *param);
int				value_count(char *line);
void			value_atoi(t_fdf *fdf, char **argv);
void			draw_vertical(t_fdf *fdf);
void			draw_horizontal(t_fdf *fdf);
void			bh_dispatch(t_fdf *fdf);
void			m_neg(t_fdf *fdf);
void			m_pos(t_fdf *fdf);

#endif
