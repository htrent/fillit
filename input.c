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

void	display_message(int signal)
{
	if (signal == 1)
		write(1, "error\n", 6);
	else if (signal == 0)
		write(1, "usage: ./fillit source_file\n", 28);
}

int		check_around(char *tetrimino, int i)
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

int		validation(char *tetrimino, int byte_read)
{
	int		connects;
	int		sharps;
	int		dots;
	int		ret;
	int		i;

	if (byte_read < 19)
		return (1);
	connects = 0;
	sharps = 0;
	dots = 0;
	i = -1;
	while (++i < byte_read)
	{
		if (tetrimino[i] == '\n')
		{
			if ((i - 4) % 5 != 0 && i != 20)
				return (1);
		}
		else if (tetrimino[i] == '#')
		{
			ret = check_around(tetrimino, i);
			if (!ret)
				return (1);
			connects += ret;
			sharps++;
		}
		else if (tetrimino[i] == '.')
			dots++;
		else
			return (1);
	}
	if (sharps != 4 || dots != 12 || (connects != 6 && connects != 8))
		return (1);
	return (0);
}
