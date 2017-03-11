/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:54:01 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/11 17:56:59 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char *get_line(t_map *map, char *line)
{
	char *str;
	int i;
	int u;

	i = ft_strlen(line);
	u = 4;
	str = (char *)malloc(sizeof(char) * i - 4);
	ft_bzero(str, i - 4);
	i = 0;
	while (i != map->x)
	{
		str[i] = line[u];//recup de donner here
		i++;
		u++;
	}
	str[i] = '\0';
	return (str);
}

static t_map *creat_mapy(t_map *map)
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (i != map->y)
	{
		while (u != map->x)
		{
			map->map[i][u] = '.';
			u++;
		}
		map->map[i][u] = '\0';
		u = 0;
		i++;
	}
	return (map);
}

t_map *get_size_map(char *line, t_map *map)
{
	int i;

	i = 0;
	map->x = get_x(line);
	map->y = get_y(line);
	map->map = (char**)malloc(sizeof(char*) * map->y);
	while (i < map->x)
	{
		map->map[i] = (char*)malloc(sizeof(char) * map->x + 1);
		++i;
	}
	map = creat_mapy(map);
	return (map);
}
