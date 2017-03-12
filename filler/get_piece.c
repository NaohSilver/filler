/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:54:12 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/12 04:48:11 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_map map)
{
	int		i;

	i = -1;
	while (++i < map.coord.y)
		free(map.map[i]);
	free(map.map);
}

void	free_list(t_list **lst)
{
	if (((*lst)->next))
		free_list(&(*lst)->next);
	free((*lst)->content);
	free(*lst);
}

int		not_putable(t_map map, int side)
{
	int		i;

	i = -1;
	if (side % 2 == 0)
	{
		while (++i < map.coord.y)
		{
			if (side == 0 && map.map[i][0] == map.player)
				return (1);
			if (side == 2 && map.map[i][map.coord.x - 1] == map.player)
				return (1);
		}
	}
	else
	{
		while (++i < map.coord.x)
		{
			if (side == 1 && map.map[0][i] == map.player)
				return (1);
			if (side == 3 && map.map[map.coord.y - 1][i] == map.player)
				return (1);
		}
	}
	return (0);
}

t_coord	put_coord(t_list *all, t_list *p, t_map map)
{
	t_list	*tp;
	t_list	*tp1;
	t_coord	coord;
	t_coord	v;

	tp = all;
	coord.x = map.coord.x + 1;
	coord.y = map.coord.y + 1;
	while (tp)
	{
		tp1 = p;
		while (tp1)
		{
			v.x = ((t_coord*)(tp->content))->x + ((t_coord*)(tp1->content))->x;
			v.y = ((t_coord*)(tp->content))->y + ((t_coord*)(tp1->content))->y;
			if ((v.x == 0 && not_putable(map, 0) == 0) ||\
			(v.y == 0 && not_putable(map, 1) == 0) ||\
			(v.x == map.coord.x - 1 && not_putable(map, 2) == 0) ||\
			(v.y == map.coord.y + 1 && not_putable(map, 3) == 0))
				coord = *((t_coord*)(tp->content));
			tp1 = tp1->next;
		}
		tp = tp->next;
	}
	return (coord);
}
