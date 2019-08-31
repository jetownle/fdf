/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:06:27 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/30 15:47:18 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
** converting the ascii file into an int map
*/

void	value_atoi(t_fdf *fdf, char **argv)
{
	int fd;
	int y;
	int z;
	char *line;
	char **split;
	
	y = 0;
	z = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1 && z != fdf->map.height)
	{
		fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width);
		if((split = ft_strsplit(line, ' ')))
		{
			fdf->map.j = 0;
			while (split[fdf->map.j] && (y != fdf->map.width))
			{
				fdf->map.values[z][y] = ft_atoi(split[fdf->map.j++]);
				y += 1;
			}
		}
		y = 0;
		z += 1;
		free(line);
	}
	close(fd);
}

/* 
** checks line for digits, spaces, '-' and returns width
*/

int value_count(char *line)
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
		else if (*line != ' ' && *line != '-')
			perror("error not a valid file");
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
		fdf->map.width = value_count(*gnlread);
	}
	fdf->map.height = count;
	fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height);
	value_atoi(fdf, argv);
	return (gnlread);
}

