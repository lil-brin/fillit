/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:22:37 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/18 10:51:41 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void				ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

static t_simbols	ft_valid_size(char **buff_map)
{
	int			j;
	int			i;
	t_simbols	simbol;

	j = -1;
	simbol.count_diez = 0;
	simbol.count_dot = 0;
	simbol.buff_size = 0;
	while (buff_map[++j])
	{
		i = -1;
		while (buff_map[j][++i])
		{
			if (buff_map[j][i] == '#')
				simbol.count_diez++;
			if (buff_map[j][i] == '.')
				simbol.count_dot++;
			if ((buff_map[j][4] != '\n' || buff_map[j][9] != '\n'
				|| buff_map[j][14] != '\n' || buff_map[j][19] != '\n')
				|| (buff_map[j + 1] && buff_map[j][20] != '\n'))
				ft_error();
			simbol.buff_size++;
		}
	}
	return (simbol);
}

static int			ft_valid_len(char **buff_map)
{
	t_simbols	simbol;
	int			count_map;
	int			count_bsl_n;

	simbol = ft_valid_size(buff_map);
	count_map = simbol.count_diez / 4;
	count_bsl_n = (count_map * 4) + (count_map - 1);
	if (simbol.buff_size != (simbol.count_diez +
			simbol.count_dot + count_bsl_n) ||
			(simbol.count_diez % 4 != 0))
		ft_error();
	return (1);
}

static int			ft_valid_tetro(char **buff_map)
{
	int j;
	int i;
	int contact;

	j = 0;
	while (buff_map[j])
	{
		i = 0;
		contact = 0;
		while (buff_map[j][i])
		{
			if (buff_map[j][i] == '#')
			{
				if (buff_map[j][i + 1] == '#')
					contact++;
				if (buff_map[j][i + 5] == '#')
					contact++;
			}
			i++;
		}
		if (contact < 3 || contact > 4)
			ft_error();
		j++;
	}
	return (1);
}

int					ft_valid(char **buff_map)
{
	if (ft_valid_len(buff_map) && ft_valid_tetro(buff_map))
		return (1);
	return (0);
}
