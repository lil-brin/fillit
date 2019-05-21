/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:56:11 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/12 19:28:58 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_min_field(int tetro_num)
{
	int	n;

	n = 0;
	while (n * n < tetro_num * 4)
		n++;
	return (n);
}

char		*ft_makefield(int size)
{
	char	*field;
	int		area;
	int		i;

	i = 0;
	area = size * (size + 1);
	if (!(field = (char *)malloc(sizeof(char) * (area + 1))))
		return (NULL);
	while (i < (area - 1))
	{
		if ((i + 1) % (size + 1) == 0)
			field[i] = '\n';
		else
			field[i] = '.';
		i++;
	}
	field[i] = '\0';
	return (field);
}
