/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:54:12 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/11 17:57:38 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int get_piecey(char *line)
{
	int y;

	y = get_y(line);
	return (y);
}

static int get_piecex(char *line)
{
	int x;

	x = get_x(line);
	return (x);
}

char *get_line_piece(t_map *map, char *line)
{
	char *str;
	int i;

	i = ft_strlen(line);
	str = (char *)malloc(sizeof(char) * i + 1);
	ft_bzero(str, i + 1);
	i = 0;
	while (i != map->piecey)
	{
		str[i] = line[i];//recup de donner here
		i++;
	}
	str[i] = '\0';
	return (str);
}

static t_map *creat_piece(t_map *map)
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (i != map->piecex)
	{
		while (u != map->piecey)
		{
			map->piece[i][u] = '.';
			u++;
		}
		map->piece[i][u] = '\0';
		u = 0;
		i++;
	}
	return (map);
}

t_map *get_size_piece(t_map *map, char *line)
{
	int i;

	i = 0;
	map->piecex = get_piecex(line);
	map->piecey = get_piecey(line);
	map->piecex += 1;
	map->piece = (char**)malloc(sizeof(char*) * map->piecex);
	while (i < map->piecex)
	{
		map->piece[i] = (char*)malloc(sizeof(char) * map->piecey + 1);
		++i;
	}
	map = creat_piece(map);
	return (map);
}
