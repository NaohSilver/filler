/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:33:22 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/10 23:04:12 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*static int get_piecey(char *line)
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
}*/

static char *get_line(t_map *map, char *line)
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

static t_map *get_size_map(char *line, t_map *map)
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

int main()
{
	t_map	*map;
	char	*line;
	int i;

	i = -1;
	map = (t_map*)malloc(sizeof(t_map));
	map->err = 0;
	while (get_next_line(0, &line) > 0)// idea de parse generale
	{
		if (ft_strncmp(line, "$$$ exec p", 10) == 0)
		{
			map->player = (line[10] == '1') ? 'X' : 'O';
			map->err = 1;
		}
		if ((map->err == 1) && (ft_strncmp(line, "Plateau", 7) == 0))
		{
			get_size_map(line, map);
			map->err = 0;
		}
		if (ft_strncmp(line, "0", 1) == 0)
		{
			++i;
			ft_strcpy(map->map[i], get_line(map, line));
			ft_printf("{green}%s\n", map->map[i]);
		}
/*		if (ft_strncmp(line, "Piece ", 6) == 0)
		{
			map->piecex = get_piecex(line);
			map->piecey = get_piecey(line);
		}*/
		free(line);
	}
	while((i != map->y) && ++i)
		free(map->map[i]);
	return (0);
}
