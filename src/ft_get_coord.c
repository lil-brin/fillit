/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:25:02 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/16 19:31:51 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_write(int i, int j, int count, t_coord *coord)
{
	if (count == 0)
		coord[i].x1 = j;
	if (count == 1)
		coord[i].x2 = j;
	if (count == 2)
		coord[i].x3 = j;
	if (count == 3)
		coord[i].x4 = j;
}

t_coord		*ft_get_coord(char **buff_map, int tetro_num)
{
	int			i;
	int			j;
	int			count;
	t_coord		*coord;

	i = 0;
	coord = (t_coord *)malloc(sizeof(t_coord) * tetro_num + 1);
	coord[tetro_num].x1 = -20;
	while (buff_map[i])
	{
		j = 0;
		count = 0;
		while (buff_map[i][j])
		{
			if (buff_map[i][j] == '#')
			{
				ft_write(i, j, count, coord);
				count++;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

t_coord		*ft_first_coord_correction(t_coord *coord, int field_side)
{
	int i;

	i = 0;
	while (coord[i].x1 != -20)
	{
		coord[i].x1 = coord[i].x1 +
		(coord[i].x1 / 5) * (field_side - 4);
		coord[i].x2 = coord[i].x2 +
		(coord[i].x2 / 5) * (field_side - 4);
		coord[i].x3 = coord[i].x3 +
		(coord[i].x3 / 5) * (field_side - 4);
		coord[i].x4 = coord[i].x4 +
		(coord[i].x4 / 5) * (field_side - 4);
		i++;
	}
	return (coord);
}

t_coord		*ft_second_coord_correction(t_coord *coord, int field_side)
{
	int i;

	i = 0;
	while (coord[i].x1 != -20)
	{
		coord[i].x1 = coord[i].x1 + coord[i].x1 / field_side;
		coord[i].x2 = coord[i].x2 + coord[i].x2 / field_side;
		coord[i].x3 = coord[i].x3 + coord[i].x3 / field_side;
		coord[i].x4 = coord[i].x4 + coord[i].x4 / field_side;
		i++;
	}
	return (coord);
}
