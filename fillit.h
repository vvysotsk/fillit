/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:42:31 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/02 16:42:32 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./includes/libft.h"

typedef struct		s_tetri
{
	char			c;
	char			*str;
	int 			x[4];
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;

void	ft_error(void);
char	*ft_reading(char *str);
t_tetri	*ft_save_block(const char *str);
t_tetri	*ft_get_xy(t_tetri *list, char **ar_str);
t_tetri	*ft_update_xy(t_tetri *list);
t_tetri	*ft_new_xy(t_tetri *list, int x, int y);
char	**ft_gen_map(int max);
int		ft_max_square(t_tetri *list);
char	**ft_set_char(t_tetri *list, char **result, int max);
void	ft_check(char *str);
int		ft_check_map(t_tetri *list, char **result, int max);
char	**ft_result(t_tetri *list, int max);
#endif
