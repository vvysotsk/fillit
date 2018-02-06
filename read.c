/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:04:09 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 17:04:10 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_count_tetri(const char *str)
{
	int		dot;
	int		sharp;
	int		end_line;
	int		index;

	index = 0;
	dot = 0;
	sharp = 0;
	end_line = 0;
	while (str[index])
	{
		if (str[index] == '.')
			dot++;
		else if (str[index] == '#')
			sharp++;
		else if (str[index] == '\n')
			end_line++;
		else
			ft_error();
		index++;
	}
	if (sharp < 4 || dot % 4 || sharp % 4 || (end_line + 1) % 5)
		ft_error();
	return (sharp / 4);
}

char		**ft_set_char(t_tetri *list, char **result, int max)
{
	int		x;
	int		y;
	int		index;

	y = 0;
	index = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (list->x[index] == x && list->y[index] == y)
			{
				result[y][x] = list->c;
				index++;
			}
			x++;
		}
		result[y][x] = '\0';
		y++;
	}
	result[y] = NULL;
	return (result);
}

t_tetri		*ft_coordinates(t_tetri *list)
{
	list = ft_get_xy(list, ft_strsplit(list->str, '\n'));
	return (list);
}

t_tetri		*ft_save_block(const char *str)
{
	int		count_tetri;
	int		index;
	char	c;
	t_tetri	*temp;
	t_tetri	*buff;

	count_tetri = ft_count_tetri(str);
	index = 0;
	c = 'A';
	if (!(temp = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	buff = temp;
	while (count_tetri-- > 0)
	{
		temp->str = ft_strndup(&str[index], 20);
		ft_check(temp->str);
		temp->c = c++;
		temp = ft_coordinates(temp);
		temp = ft_update_xy(temp);
		index += 21;
		if (!(temp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		temp = temp->next;
	}
	temp->next = NULL;
	return (buff);
}

char		*ft_reading(char *str)
{
	int		fd;
	int		index;
	char	*buffer;

	index = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	if (!(buffer = ft_strnew(546)))
		ft_error();
	read(fd, buffer, 546);
	while (buffer[index])
	{
		if (buffer[index] == 'a')//  should be deleted
			buffer[index] = '\n';
		index++;
	}
	if (index < 19)
		ft_error();
	close(fd);
	return (buffer);
}
