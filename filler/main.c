/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 01:33:22 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/11 17:58:16 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	free(map->map);
	i = -1;
	while((i != map->piecex) && ++i)
		free(map->piece[i]);
	free(map->piece);
}

int main()//remaitre a 25ligne
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
