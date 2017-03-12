/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 04:24:55 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/12 03:16:57 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int get_nbr(char *line)
{
	int i;
	int u;

	i = 8;
	u = 0;
	while (ft_isdigit(line[i]) == 1)
	{
		++i;
		++u;
	}
	++u;
	return (u);
}

int get_y(char *line)
{
	int i;
	int u;
	char *str;

	i = 8;
	u = 0;
	str = (char*)malloc(sizeof(char) * get_nbr(line));
	while (ft_isdigit(line[i]) == 1)
	{
		str[u] = line[i];
		++u;
		++i;
	}
	u++;
	str[u] = '\0';
	u = ft_atoi(str);
	free(str);
	return (u);
}

static int get_start(char *line)
{
	int i;

	i = 8;
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	return (i);
}

static int get_nbr2(char *line)
{
	int i;
	int u;

	i = get_start(line);
	u = 0;
	while (ft_isdigit(line[i]) == 1)
	{
		++i;
		++u;
	}
	++u;
	return (u);
}

int get_x(char *line)
{
	int i;
	int u;
	char *str;

	i = get_start(line);
	u = 0;
	str = (char*)malloc(sizeof(char) * get_nbr2(line));
	while (ft_isdigit(line[i]) == 1)
	{
		str[u] = line[i];
		++u;
		++i;
	}
	u++;
	str[u] = '\0';
	u = ft_atoi(str);
	free(str);
	return (u);
}
