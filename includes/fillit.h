/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:19:38 by vmuravio          #+#    #+#             */
/*   Updated: 2018/03/05 16:03:34 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define BUFF_SIZE 21

char			*ft_move_left(char *str);
int				ft_valid(char **buff_map);
void			ft_error();
char			*ft_move_top(char *str);
void			ft_move_tetro(char **buff_map);

char			*ft_move_left(char *str);
char			*ft_move_top(char *str);
void			ft_move_tetro(char **buff_map);

typedef struct	s_coord
{
	int	x1;
	int	x2;
	int	x3;
	int	x4;
}				t_coord;

void			ft_coord_corection(t_coord *coord, int side);
void			ft_write(int i, int j, int count, t_coord *coord);
t_coord			*ft_get_coord(char	**buff_map, int tetro_num);
char			**ft_read_map(int argc, char **argv);
int				ft_min_field(int nbr);
char			*ft_makefield(int size);
int				ft_count_tetro(char **field);
char			*ft_put_tetro(t_coord *coord, char *field,
					int shift, int currtetro);
char			*ft_rm_tetro(t_coord *coord, char *field,
					int shift, int currtetro);
int				ft_try_tetro(t_coord *coord, char *field,
					int shift, int currtetro);
t_coord			*ft_first_coord_correction(t_coord *coord,
					int field_side);
t_coord			*ft_second_coord_correction(t_coord *coord, int field_side);
int				ft_solve(t_coord *coord, char *field,
					int nbr_tetro, int tetronum);
int				ft_fieldlen(char *field);
typedef struct	s_simbols
{
	int	count_diez;
	int	buff_size;
	int	count_dot;
}				t_simbols;
#endif
