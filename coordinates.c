/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:00:16 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 17:00:18 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_tetri	*ft_get_xy(t_tetri *list, char **ar_str)
{
	int	index;
	int	x;
	int	y;

	y = 0;
	index = 0;
	while (ar_str[y])
	{
		x = 0;
		while (ar_str[y][x])
		{
			if (ar_str[y][x] == '#')
			{
				list->x[index] = x;
				list->y[index] = y;
				index++;
			}
			x++;
		}
		y++;
	}
	return (list);
}

t_tetri	*ft_update_xy(t_tetri *list)
{
	int	xmin;
	int	ymin;
	int	index;

	index = 1;
	xmin = list->x[0];
	ymin = list->y[0];
	while (index != 4)
	{
		if (list->x[index] < xmin)
			xmin = list->x[index];
		if (list->y[index] < ymin)
			ymin = list->y[index];
		index++;
	}
	while (--index >= 0)
	{
		list->x[index] = list->x[index] - xmin;
		list->y[index] = list->y[index] - ymin;
	}
	return (list);
}

t_tetri	*ft_new_xy(t_tetri *list, int x, int y)
{
	int	count;

	count = 3;
	while (count >= 0)
	{
		list->x[count] += x - list->x[0];
		list->y[count] += y - list->y[0];
		count--;
	}
	return (list);
}

char	**ft_gen_map(char **map, int max)
{
	int	x;
	int	y;

	y = 0;
	if (!(map = (char **)malloc((max + 1))))
		return (NULL);
	while (y < max)
	{
		map[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	map[y] = NULL;
	return (map);
}
