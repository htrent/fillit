/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/22 15:22:51 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>		// unistd.h

#include <stdio.h>

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

int		main(int argv, char **argc)
{
	char	*buffer;
	int		byte_read;
	int		fd;

	if (argv == 2)
	{
		if ((fd = open(argc[1], O_RDONLY)) == -1)
		{
			display_message(1);
			return (1);
		}
		buffer = (char *)malloc(sizeof(char) * 22);
		while ((byte_read = read(fd, buffer, 21 + 5)))	// vs bug?
		{
			buffer[byte_read] = '\0';
			if (validation(buffer, byte_read))
			{
				display_message(1);
				return (1);
			}
		}
		if (strlen(buffer) != 20) ///_ft_strlen!!!
		{
			display_message(1);
			return (1);
		}
		close(fd);
	}
	else
		display_message(0);
	return (0);
}
