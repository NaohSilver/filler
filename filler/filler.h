/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:31:51 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/11 17:43:06 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ERROR -42
# define P1 'O'
# define p2 'X'
# define print ft_printf("yo\n")
# define printi ft_printf("%i\n", i)
# define printu ft_printf("%i\n", u)

# include "print/libft/libft.h"
# include "print/ft_printf.h"
# include "print/libft/get_next_line.h"

typedef struct	s_map
{
	char			player;
	int				x;
	int				y;
	int				err;
	int				piecex;
	int				piecey;
	int				get_x;
	int				get_y;
	char			**map;
	char			**piece;
}					t_map;

void creat_map(char *line, t_map *map);
int get_x(char *line);
int get_y(char *line);

#endif
