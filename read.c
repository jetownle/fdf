/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:06:27 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/22 03:52:57 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
** strsplits the line and then stores the converted int values in the struct
*/

void value_splatoi(t_fdf *fdf, int y, int z, char *line)
{
	int		i;
	char	**split;

	if((split = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (split[i] && (y != fdf->map.width))
		{
			fdf->map.values[z][y] = ft_atoi(split[i++]);
			y++;
		}
		free(split);
	}
}

/* 
** converting the ascii file into an int map
*/

void	value_atoi(t_fdf *fdf, int fd)
{
	int y;
	int z;
	char *line;

	y = 0;
	z = 0;
	while (get_next_line(fd, &line) == 1 && z != fdf->map.height)
	{
		if(!(fdf->map.values[z] = (int *)malloc(sizeof(int) * fdf->map.width)))
			perror(error mallocing values[z]);
		value_splatoi(fdf, y, z, line);
		y = 0;
		z++;
		free(line);
	}
}

/* 
** checks line for digits, spaces, '-' and returns length (columns)
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
** width and length of the map, lines should all be same length
*/

int count_lines(t_fdf *fdf, int fd)
{
	int len;
	int rows;
	int cols;
	char *line;

	rows = 0;
	cols = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if ((len = value_count(line)) > cols)
			cols = len;
		(cols == len) ? rows++ : perror("error not a valid file");
		free(line);
	}
	fdf->map.width = cols;
	return (rows);
}
		
/* 
** reads input file into a double pointer array gnlread
** do I even need this? who knows
*/

char	**ft_read(int fd)
{
	char	**gnlread;
	char	**temp;
	char	*holder;
	size_t	i;
	size_t	count;

	if (fd < 0)
		return (NULL);
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
	}
	return (gnlread);
}

