/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:03:12 by vmuravio          #+#    #+#             */
/*   Updated: 2018/01/18 12:56:16 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	char		**buff_map;
	t_coord		*coord;
	char		*field;
	int			tetro_num;
	int			minfield;

	buff_map = ft_read_map(argc, argv);
	ft_valid(buff_map);
	tetro_num = ft_count_tetro(buff_map);
	ft_move_tetro(buff_map);
	minfield = ft_min_field(tetro_num);
	coord = ft_get_coord(buff_map, tetro_num);
	free(*buff_map);
	if (tetro_num == 1 && coord[0].x1 == 0 &&
		coord[0].x2 == 1 && coord[0].x3 == 2 && coord[0].x4 == 3)
		minfield++;
	field = ft_makefield(minfield);
	ft_first_coord_correction(coord, ft_fieldlen(field));
	ft_solve(coord, field, tetro_num, 0);
	write(1, "\n", 1);
	return (0);
}
