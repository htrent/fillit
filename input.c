/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/12 17:16:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_valid(t_valid *v)
{
	v->connects = 0;
	v->sharps = 0;
	v->dots = 0;
	v->i = -1;
}

int				display_message(int signal)
{
	if (signal == -1)
		write(1, "error\n", 6);
	else if (signal == 0)
		write(1, "usage: ./fillit source_file\n", 28);
	return (1);
}

static int		check_around(char *tetrimino, int i)
{
	int connects;

	connects = 0;
	if ((i - 4) % 5 == 0 || i == 20)
		return (0);
	if (i % 5 != 0 && tetrimino[i - 1] == '#')
		connects++;
	if ((i - 3) % 5 != 0 && tetrimino[i + 1] == '#')
		connects++;
	if (i > 3 && tetrimino[i - 5] == '#')
		connects++;
	if (i < 14 && tetrimino[i + 5] == '#')
		connects++;
	return (connects);
}

int				validation(char *tetrimino, int byte_read)
{
	t_valid v;

	init_valid(&v);
	while (++v.i < byte_read)
		if (tetrimino[v.i] == '\n')
		{
			if ((v.i - 4) % 5 != 0 && v.i != 20)
				return (1);
		}
		else if (tetrimino[v.i] == '#')
		{
			v.ret = check_around(tetrimino, v.i);
			if (!v.ret)
				return (1);
			v.connects += v.ret;
			v.sharps++;
		}
		else if (tetrimino[v.i] == '.')
			v.dots++;
		else
			return (1);
	if (v.sharps != 4 || v.dots != 12 || (v.connects != 6 && v.connects != 8))
		return (1);
	return (0);
}
