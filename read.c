/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:06:27 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/09 17:56:56 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

