/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/01 12:51:39 by htrent           ###   ########.fr       */
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
	if ((i - 4) % 5 == 0 || i == 20)
		return (1);
	else if (i % 5 != 0 && tetrimino[i - 1] == '#')
		return (0);
	else if ((i - 3) % 5 != 0 && tetrimino[i + 1] == '#')
		return (0);
	else if (i > 3 && tetrimino[i - 5] == '#')
		return (0);
	else if (i < 13 && tetrimino[i + 5] == '#')
		return (0);
	else
		return (1);
}

int		validation(char *tetrimino, int byte_read)
{
	int		sharps;
	int		dots;
	int		i;

	if (byte_read < 19)
		return (1);
	sharps = 0;
	dots = 0;
	i = 0;
	while (i < byte_read)
	{
		if (tetrimino[i] == '\n')
		{
			if ((i - 4) % 5 != 0 && i != 20)
				return (1);
		}
		else if (tetrimino[i] == '#')
		{
			if (check_around(tetrimino, i))
				return (1);
			sharps++;
		}
		else if (tetrimino[i] == '.')
			dots++;
		else
			return (1);
		i++;
	}
	if (sharps != 4 || dots != 12)
		return (1);
	return (0);
}
