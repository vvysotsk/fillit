/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:04:50 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 17:04:51 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_map(t_tetri *list, char **result, int max)
{
	int		count;

	count = 0;
	while (count < 4)
	{
		if ((list->y[count] >= 0 && list->y[count] < max) &&
			(list->x[count] >= 0 && list->x[count] < max) &&
			result[list->y[count]][list->x[count]] == '.')
		{
			count++;
			if (count == 4)
				return (0);
		}
		else
			break ;
	}
	return (1);
}

int			ft_max_square(t_tetri *list)
{
	int		counter;
	int		max;

	counter = 0;
	max = 2;
	while (list->next)
	{
		list = list->next;
		counter++;
	}
	while (max * max < counter * 4)
		max++;
	return (max);
}

char		**ft_gen_map(int max)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char*) * (max + 1))))
		ft_error();
	while (y < max)
	{
		x = 0;
		if (!(map[y] = (char*)malloc(sizeof(char) * max + 1)))
			ft_error();
		while (x < max)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}
