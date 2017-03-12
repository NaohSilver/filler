/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:54:01 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/12 04:54:22 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		put_piece(t_coord i, t_piece p, t_map map)
{
	t_list	*tmp;
	t_coord	*in;
	int		touch;

	tmp = p.piece;
	touch = 0;
	while (tmp)
	{
		in = tmp->content;
		if (i.y + in->y < 0 || i.y + in->y >= map.coord.y ||\
			i.x + in->x < 0 || i.x + in->x >= map.coord.x)
			return (0);
		if (map.map[i.y + in->y][i.x + in->x] != map.player && \
			map.map[i.y + in->y][i.x + in->x] != '.')
			return (0);
		if (map.map[i.y + in->y][i.x + in->x] == map.player)
			touch++;
		tmp = tmp->next;
	}
	return (touch == 1 ? 1 : 0);
}

t_list	*get_all_possition(t_piece piece, t_map map)
{
	t_coord	coord;
	t_list	*lst;

	coord.y = -(piece.coord.y) - 1;
	lst = NULL;
	while (++(coord.y) <= map.coord.y - piece.coord.y)
	{
		coord.x = -(map.coord.x) - 1;
		while (++(coord.x) <= map.coord.x - piece.coord.x)
			if (put_piece(coord, piece, map) == 1)
				ft_lstadd_back(&lst, ft_lstnew(&coord, sizeof(t_coord)));
	}
	return (lst);
}

t_coord	get_value(t_list *tmp, t_list *tmp1, t_list *tmp2, t_coord *val)
{
	t_coord	coord;

	coord.x = -1;
	coord.y = -1;
	if (ft_abs(((t_coord*)(tmp1->content))->x + ((t_coord*)\
	(tmp->content))->x - ((t_coord*)(tmp2->content))->x) + ft_abs((\
	(t_coord*)(tmp1->content))->y + ((t_coord*)(tmp->content))->y -\
	((t_coord*)(tmp2->content))->y) <= val->x + val->y)
	{
		val->x = ft_abs(((t_coord*)(tmp1->content))->x + ((t_coord*)\
		(tmp->content))->x - ((t_coord*)(tmp2->content))->x);
		val->y = ft_abs(((t_coord*)(tmp1->content))->y + ((t_coord*)\
		(tmp->content))->y - ((t_coord*)(tmp2->content))->y);
		coord = *((t_coord*)(tmp->content));
	}
	return (coord);
}

t_coord	get_coord_hard(t_list *all, t_list *p, t_list *p2, t_coord size)
{
	t_list	*tmp;
	t_list	*tmp1;
	t_list	*tmp2;
	t_coord	val;
	t_coord	co;

	tmp = all;
	val = size;
	while (tmp)
	{
		tmp1 = p;
		while (tmp1)
		{
			tmp2 = p2;
			while (tmp2)
			{
				if (get_value(tmp, tmp1, tmp2, &val).x != -1)
					co = get_value(tmp, tmp1, tmp2, &val);
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (co);
}

t_coord	get_lst_coord(t_piece piece, t_map map, t_list *lst)
{
	t_coord	coord;
	t_list	*lst2;

	lst2 = get_all_possition(piece, map);
	if (!lst2)
	{
		coord.x = 0;
		coord.y = 0;
		free_map(map);
	}
	else
	{
		if (lst && put_coord(lst2, piece.piece, map).y < map.coord.y)
			coord = put_coord(lst2, piece.piece, map);
		else if (!lst || (map.coord.y == 15 && map.player == 'X'))
			coord = *((t_coord*)(lst2->content));
		else
			coord = get_coord_hard(lst2, piece.piece, lst, map.coord);
		free_list(&lst2);
	}
	return (coord);
}
