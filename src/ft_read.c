/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:05:23 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/18 13:12:58 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_read_map(int argc, char **argv)
{
	int		fd;
	int		n;
	char	buffer[BUFF_SIZE + 1];
	char	**buff_map;

	n = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
	ft_bzero(buffer, BUFF_SIZE + 1);
	buff_map = (char**)malloc(sizeof(char*) * (27));
	if (!buff_map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, buffer, BUFF_SIZE) && (n <= 26))
	{
		buff_map[n] = ft_strdup(buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		n++;
	}
	close(fd);
	buff_map[n] = NULL;
	return (buff_map);
}

int			ft_count_tetro(char **field)
{
	int i;

	i = 0;
	while (field[i])
		i++;
	return (i);
}
