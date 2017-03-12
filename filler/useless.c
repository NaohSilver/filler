/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 04:50:39 by niludwig          #+#    #+#             */
/*   Updated: 2017/03/12 04:51:22 by niludwig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	new->next = NULL;
	if (!(*alst))
		*alst = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
