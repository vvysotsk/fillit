/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:42:01 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 16:42:03 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_reset(t_tetri *list, char **result, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (result[y][x] == list->c)
				result[y][x] = '.';
			x++;
		}
		y++;
	}
	return (result);
}

static char	**ft_solve(t_tetri *list, char **result, int max)
{
	int		x;
	int		y;
	char	**final_res;

	if (list->next == NULL)
		return (result);
	final_res = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			list = ft_new_xy(list, x, y);
			if (ft_check_map(list, result, max) == 0)
				final_res = ft_solve(list->next, \
					ft_set_char(list, result, max), max);
			if (final_res)
				return (final_res);
			result = ft_reset(list, result, max);
			x++;
		}
		++y;
	}
	return (NULL);
}

char		**ft_result(t_tetri *list, int max)
{
	char	**result;

	result = NULL;
	while (!result)
	{
		result = ft_gen_map(max);
		result = ft_solve(list, result, max);
		max++;
	}
	return (result);
}
