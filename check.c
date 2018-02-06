/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:42:47 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 16:42:49 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_structure(char *str, int index)
{
	if (str[index] == '#')
	{
		str[index] = '+';
		str = ft_structure(str, index + 1);
	}
	if(str[index + 1] == '#')
	{
		str[index + 1] = '+';
		str = ft_structure(str, index + 1);
	}
	if(str[index - 1] >= 0 && str[index - 1] == '#')
	{
		str[index - 1] = '+';
		str = ft_structure(str, index - 1);
	}
	if(index + 5 <= 20  && str[index + 5] == '#')
	{
		str[index + 5] = '+';
		str = ft_structure(str, index + 5);
	}
	if(index - 5 >= 0 && str[index - 5] == '#')
	{
		str[index - 5] = '+';
		str = ft_structure(str, index - 5);
	}
	return (str);
}

int		ft_count_plus(char *str)
{
	int	counter;
	int	index;

	index = 0;
	counter = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '+')
			counter++;
		index++;
	}
	return (counter);
}

void	ft_check(char *str)
{
	int	index;

	index = 0;
	while (str[index] && str[index] != '#')
		index++;
	str[index] = '+';
	str = ft_structure(str, index);
	if (ft_count_plus(str) != 4)
		ft_error();
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '+')
			str[index] = '#';
		index++;
	}
}

int		ft_check_map(t_tetri *list, char **result, int max)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if ((list->y[count] >= 0 && list->y[count] < max) &&
			(list->x[count] >= 0 && list->x[count]< max) &&
			result[list->y[count]][list->x[count]] == '.')
		{
			count++;
			if (count == 4)
				return (0);
		}
		else
			break;
	}
	return (1);
}
