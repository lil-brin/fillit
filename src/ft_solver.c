/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:05:33 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/16 19:38:54 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_fieldlen(char *field)
{
	int		i;

	i = 0;
	while (field[i] == '.')
		i++;
	return (i);
}

int		ft_solve(t_coord *coord, char *field, int nbr_tetro, int tetronum)
{
	size_t	shift;
	int		flag;

	if (tetronum >= nbr_tetro)
	{
		ft_putstr(field);
		return (1);
	}
	shift = -1;
	while (++shift < ft_strlen(field))
	{
		if ((flag = ft_try_tetro(coord, field, shift, tetronum)))
		{
			field = ft_put_tetro(coord, field, shift, tetronum);
			if (ft_solve(coord, field, nbr_tetro, tetronum + 1))
				return (1);
		}
		if (flag)
			ft_rm_tetro(coord, field, shift, tetronum);
	}
	if (tetronum == 0)
		return (ft_solve(ft_second_coord_correction(coord,
			ft_fieldlen(field) + 1),
		ft_makefield(ft_fieldlen(field) + 1), nbr_tetro, 0));
		return (0);
}
