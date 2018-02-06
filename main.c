/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:41:52 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 16:41:53 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit (0);
}

int main(int argc, char **argv)
{
	t_tetri	*list;
	char	*reading;
	char	**result;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit map_file");
		return (0);
	}
	reading = ft_reading(argv[1]);
	list = ft_save_block(reading);
	result = ft_result(list, ft_max_square(list));
	free(list);
	free(reading);
	while (*result)
		ft_putendl(*result++);
	free(result);
	return (0);
}
