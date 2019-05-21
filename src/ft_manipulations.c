/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:05:04 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/12 19:10:53 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_put_tetro(t_coord *coord, char *field, int shift, int currtetro)
{
	field[coord[currtetro].x1 + shift] = 'A' + currtetro;
	field[coord[currtetro].x2 + shift] = 'A' + currtetro;
	field[coord[currtetro].x3 + shift] = 'A' + currtetro;
	field[coord[currtetro].x4 + shift] = 'A' + currtetro;
	return (field);
}

char	*ft_rm_tetro(t_coord *coord, char *field, int shift, int currtetro)
{
	field[coord[currtetro].x1 + shift] = '.';
	field[coord[currtetro].x2 + shift] = '.';
	field[coord[currtetro].x3 + shift] = '.';
	field[coord[currtetro].x4 + shift] = '.';
	return (field);
}

int		ft_try_tetro(t_coord *coord, char *field, int shift, int currtetro)
{
	if (field[coord[currtetro].x1 + shift] != '.' ||
	field[coord[currtetro].x2 + shift] != '.' ||
	field[coord[currtetro].x3 + shift] != '.' ||
	field[coord[currtetro].x4 + shift] != '.' ||
	coord[currtetro].x1 + shift > (int)ft_strlen(field) ||
	coord[currtetro].x2 + shift > (int)ft_strlen(field) ||
	coord[currtetro].x3 + shift > (int)ft_strlen(field) ||
	coord[currtetro].x4 + shift > (int)ft_strlen(field))
		return (0);
	return (1);
}
