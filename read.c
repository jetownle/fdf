/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:06:27 by jetownle          #+#    #+#             */
/*   Updated: 2019/09/04 04:32:47 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *fdf)
{
	fdf->scalx = 20;
	fdf->scaly = 20;
	fdf->startx = 850;
	fdf->starty = 50;
}

/*
** converting the ascii file into an int map
*/

void	value_atoi(t_fdf *fdf, char **argv)
{
	int		fd;
	int		y;
	int		z;
	char	*line;
	char	**split;

	y = -1;
	z = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1 && z != fdf->height)
	{
		fdf->values[z] = (int *)malloc(sizeof(int) * fdf->width);
		if ((split = ft_strsplit(line, ' ')))
		{
			fdf->j = 0;
			while (split[fdf->j] && (++y != fdf->width))
			{
				fdf->values[z][y] = ft_atoi(split[fdf->j++]);
			}
		}
		y = 0;
		z += 1;
	}
	close(fd);
}

/*
** checks line for digits, spaces, '-' and returns width
*/

int		value_count(char *line)
{
	int		len;

	len = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			len++;
			while (ft_isdigit(*line))
				line++;
		}
		else if (*line == ' ' || *line == '-')
			line++;
	}
	return (len);
}

/*
** reads input file into a double pointer array gnlread
** do I even need this? who knows
*/

char	**ft_read(t_fdf *fdf, int fd, char **argv)
{
	char	**gnlread;
	char	**temp;
	char	*holder;
	size_t	i;
	size_t	count;

	count = 0;
	gnlread = NULL;
	while (get_next_line(fd, &holder) == 1)
	{
		i = 0;
		temp = gnlread;
		if (!(gnlread = (char **)ft_memalloc(sizeof(char *) * (++count + 2))))
			return (NULL);
		if (count > 1)
			while (temp[++i - 1])
				gnlread[i - 1] = temp[i - 1];
		gnlread[count - 1] = holder;
		ft_strdel((char **)&temp);
		fdf->width = value_count(*gnlread);
	}
	fdf->height = count;
	fdf->values = (int **)malloc(sizeof(int *) * fdf->height);
	value_atoi(fdf, argv);
	return (gnlread);
}
