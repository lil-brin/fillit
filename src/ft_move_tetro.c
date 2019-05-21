/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:05:15 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/12 19:10:22 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		*ft_move_left(char *str)
{
	int		i;
	int		j;
	int		k;

	while (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
	{
		j = 0;
		while (j < 16)
		{
			i = 0;
			while (i < 3)
			{
				str[i + j] = str[i + j + 1];
				i++;
			}
			j = j + 5;
		}
		k = 3;
		while (k < 19)
		{
			str[k] = '.';
			k = k + 5;
		}
	}
	return (str);
}

char		*ft_move_top(char *str)
{
	int		i;
	int		j;
	int		k;

	while (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
	{
		j = 0;
		while (j < 11)
		{
			i = 0;
			while (i < 4)
			{
				str[i + j] = str[i + j + 5];
				i++;
			}
			j = j + 5;
		}
		k = 15;
		while (k < 19)
		{
			str[k] = '.';
			k++;
		}
	}
	return (str);
}

void		ft_move_tetro(char **buff_map)
{
	int i;

	i = 0;
	while (buff_map[i])
	{
		ft_move_left(buff_map[i]);
		ft_move_top(buff_map[i]);
		i++;
	}
}
