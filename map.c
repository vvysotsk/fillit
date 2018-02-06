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

int		ft_max_square(t_tetri *list)
{
	int	counter;
	int	max;

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
