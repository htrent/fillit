/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by htrent            #+#    #+#             */
/*   Updated: 2019/10/03 11:15:42 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_fill(t_list *tetrimino, char **field, t_point *p)
{
	int pos;

	pos = 0;
	while (pos < 4)
	{
		field[p->y + tetrimino->figure[pos][0]]
		[p->x + tetrimino->figure[pos][1]] = tetrimino->alpha;
		pos++;
	}
	tetrimino->place.x = p->x;
	tetrimino->place.y = p->y;
	p->x = 0;
	p->y = 0;
	return (field);
}

int		ft_fill_field(t_list *tetrimino, char **field, int n, t_point p)
{
	int	check;

	while (tetrimino)
	{
		check = ft_check_field(field, tetrimino, &p, n);
		if (check == 2)
		{
			if (tetrimino->prev != NULL)
			{
				field = ft_delete_tetrimino(field, tetrimino->prev, &p, n);
				tetrimino = tetrimino->prev;
			}
			else
				return (0);
		}
		if (check == 1)
		{
			field = ft_fill(tetrimino, field, &p);
			if (tetrimino->next == NULL)
				return (1);
			tetrimino = tetrimino->next;
		}
	}
	return (0);
}
