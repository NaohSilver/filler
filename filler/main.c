/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:33:22 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/12 05:41:47 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece			get_piece(void)
{
	t_coord		coord;
	t_piece		piece;
	char		*line;

	get_next_line(0, &line);
	piece.coord.y = get_y(line);
	piece.coord.x = get_x(line);
	piece.piece = NULL;
	free(line);
	piece.coord.y = -1;
	while (++(coord.y) < piece.coord.y)
	{
		get_next_line(0, &line);
		coord.x = -1;
		while (++(coord.x) < piece.coord.x)
			if (line[coord.x] == '*')
			{
				ft_lstadd_back(&(piece.piece)
				, ft_lstnew(&coord, sizeof(t_coord)));
			}
		free(line);
	}
	return (piece);
}

t_list *get_info_map(t_map *map)
{
	t_coord		coord;
	t_list		*lst;
	char		*line;

	lst = NULL;
	coord.y = -1;
	while (++(coord.y) < map->coord.y)
	{
		get_next_line(0, &line);
		coord.x = -1;
		while (++(coord.x) < map->coord.x)
		{
			if (map->map[coord.y][coord.x] != line[coord.x + 4] &&\
				line[coord.x + 4] != map->player && line[coord.x + 4] != '.')
				ft_lstadd_back(&lst, ft_lstnew(&coord, sizeof(t_coord)));
			map->map[coord.y][coord.x] = line[coord.x + 4];
		}
	free(line);
	}
	return (lst);
}

static void creat_map(char *line, t_map *map)
{
	t_coord	coord;
	int		i;

	i = 0;
	if (map->err == 1)
	{
		coord.y = get_y(line);
		coord.x = get_x(line);
		map->map = (char**)malloc(sizeof(char*) * coord.y);
		while (i < map->coord.x)
		{
			map->map[i] = (char*)malloc(sizeof(char) * coord.x + 1);
			ft_bzero(map->map[i], coord.x + 1);
			++i;
		}
		map->err = 0;
	}
	get_next_line(0, &line);
	free(line);
}

t_coord		get_coord(t_map map)
{
	t_coord	coord;
	t_piece	piece;
	t_list	*lst;

	lst = get_info_map(&map);
	piece = get_piece();
	coord = get_lst_coord(piece, map, lst);
	return (coord);
}

int main()
{
	t_map	map;
	t_coord	coord;
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$ exec p", 10) == 0)
		{
			map.player = (line[10] == '1') ? 'O' : 'X';
			map.err = 1;
		}
		else if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			creat_map(line, &map);
			coord = get_coord(map);
			ft_printf("%d %d\n", coord.y, coord.x);
		}
		free(line);
	}
	return (0);
}
