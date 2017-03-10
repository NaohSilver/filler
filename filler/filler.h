/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:31:51 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/10 22:41:51 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ERROR -42
# define P1 'O'
# define p2 'X'
# define print ft_printf("you\n")

# include "print/libft/libft.h"
# include "print/ft_printf.h"
# include "print/libft/get_next_line.h"

typedef struct		s_piece
{
	int				x;
	int				y;
	int				i;
	int				err;
	char			**piece;
}					t_piece;

typedef struct	s_map
{
	char			player;
	int				x;
	int				y;
	int				err;
	int				piecex;
	int				piecey;
	char			**map;
}					t_map;

void creat_map(char *line, t_map *map);
int get_x(char *line);
int get_y(char *line);

#endif
