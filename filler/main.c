/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:33:22 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/11 17:50:31 by niludwig         ###   ########.fr       */
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

static char *get_line_piece(t_map *map, char *line)
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

static t_map *get_size_piece(t_map *map, char *line)
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

static int ft_pars(t_map *map, char *line)
{
	if (ft_strncmp(line, "$$$ exec p", 10) == 0)
	{
		map->player = (line[10] == '1') ? 'X' : 'O';
		map->err = 1;
		return (1);
	}
	if ((map->err == 1) && (ft_strncmp(line, "Plateau", 7) == 0))
	{
		get_size_map(line, map);
		map->err = 0;
		return (1);
	}
	if (ft_strncmp(line, "Piece ", 6) == 0)
	{
		get_size_piece(map, line);
		return (1);
	}
	return (0);
}

static t_map *get_x_y(t_map *map)
{
	//a fair
	map->get_x = 1;
	map->get_y = 1;
	return (map);
}

static void get_free(t_map *map)
{
	int i;

	i = -1;
	while((i != map->y) && ++i)
		free(map->map[i]);
	i = -1;
	while((i != map->piecex) && ++i)
		free(map->piece[i]);
}

int main()
{
	t_map	*map;
	char	*line;
	int i;
	int u;

	i = -1;
	u = -1;
	map = (t_map*)malloc(sizeof(t_map));
	map->err = 0;
	while (get_next_line(0, &line) > 0)// idea de parse generale
	{
		if (ft_pars(map, line) != 0)
			;
		else if (ft_strncmp(line, "0", 1) == 0)
		{
			++i;
			ft_strcpy(map->map[i], get_line(map, line));
			ft_printf("{green}%s\n", map->map[i]);
		}
		else if ((ft_strncmp(line, ".", 1) == 0 )
		|| (ft_strncmp(line, "*", 1) == 0))
		{
			++u;
			ft_strcpy(map->piece[u], get_line_piece(map, line));
			ft_printf("{red}%s\n", map->piece[u]);
		}
		free(line);
	}
	map = get_x_y(map);
	ft_printf("{eoc}%i %i\n", map->get_y, map->get_x);
	get_free(map);
	return (0);
}
