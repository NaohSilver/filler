/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:31:51 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/12 05:30:46 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ERROR -42

# include "print/libft/libft.h"
# include "print/ft_printf.h"
# include "print/libft/get_next_line.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_peice
{
	t_list		*piece;
	t_coord		coord;
}				t_piece;

typedef struct	s_map
{
	t_coord		coord;
	int			err;
	char		**map;
	char		player;
}				t_map;

t_coord			get_coord(t_map map);
t_coord			put_coord(t_list *all, t_list *p, t_map map);
t_coord			get_lst_coord(t_piece piece, t_map map, t_list *lst);
t_coord			get_coord_hard(t_list *all, t_list *p, t_list *p2, t_coord size);
t_coord			get_value(t_list *tmp, t_list *tmp1, t_list *tmp2, t_coord *val);
t_list			*get_info_map(t_map *map);
t_list			*get_all_possition(t_piece piece, t_map map);
t_piece			get_piece(void);
int				not_putable(t_map map, int side);
int				put_piece(t_coord i, t_piece p, t_map map);
int				get_x(char *line);
int				get_y(char *line);
int				ft_abs(int i);
void			free_list(t_list **lst);
void			free_map(t_map map);
void			ft_lstadd_back(t_list **alst, t_list *new);

#endif
