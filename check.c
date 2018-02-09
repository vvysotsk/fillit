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

#include "fillit.h"

static char	*ft_structure(char *str, int index)
{
	if (str[index + 1] == '#')
	{
		str[index + 1] = '+';
		str = ft_structure(str, index + 1);
	}
	if (str[index - 1] >= 0 && str[index - 1] == '#')
	{
		str[index - 1] = '+';
		str = ft_structure(str, index - 1);
	}
	if (index + 5 <= 20 && str[index + 5] == '#')
	{
		str[index + 5] = '+';
		str = ft_structure(str, index + 5);
	}
	if (index - 5 >= 0 && str[index - 5] == '#')
	{
		str[index - 5] = '+';
		str = ft_structure(str, index - 5);
	}
	return (str);
}

static int	ft_count_plus(char *str)
{
	int		counter;
	int		index;

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

static void	ft_check_xy(char *str)
{
	if (str[4] != '\n')
		ft_error();
	else if (str[9] != '\n')
		ft_error();
	else if (str[14] != '\n')
		ft_error();
	else if (str[19] != '\n')
		ft_error();
}

void		ft_check(char *str)
{
	int		index;

	index = 0;
	while (str[index] && str[index] != '#')
		index++;
	str[index] = '+';
	ft_check_xy(str);
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

void		ft_check_char(char c)
{
	if (c == '.' || c == '#')
		ft_error();
}
