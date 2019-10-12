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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int 	ft_sqrt(int n)
{
	int i;

	i = 0;
	if (n < 0)
		return (0);
	while (i * i < n)
		i++;
	if (i * i != n)
		i--;
	return (i);
}

char 	**ft_fill(t_list *tetrimino, char **field, t_point p)
{
	int pos;

	pos = 0;
	while (pos < 4)
	{
		field[p.y + tetrimino->figure[pos][0]][p.x + tetrimino->figure[pos][1]] = tetrimino->alpha;
		pos++;
	}
	return (field);
}

char 	**ft_fill_field(t_list *tetrimino, char **field, int *n, t_point p)
{
    int check;

    //getchar();
	//ft_print_field(field, *n);
	check = ft_check_field(field, tetrimino, p, *n);
	//printf( "y: %d  x: %d         \n"
	//		"check               %d\n"
	//		"cur fig:            %c\n",p.y, p.x, check, tetrimino->alpha);
	if (check == -1)
	{
		p.y++;
		p.x = 0;
		return (ft_fill_field(tetrimino, field, n, p));
	}
	if (check == 0)
	{
		p.x++;
		return (ft_fill_field(tetrimino, field, n, p));
	}
	if (check == 2)
	{
		if (tetrimino->prev != NULL)
		{
			field = ft_delete_tetrimino(field, tetrimino->prev, &p, *n);
			return (ft_fill_field(tetrimino->prev, field, n, p));
		}
		field = ft_reinit_field(field, *n + 1, n);
		p.x = 0;
		p.y = 0;
		return (ft_fill_field(tetrimino, field, n, p));
	}
    if (field[p.y + tetrimino->figure[0][0]][p.x + tetrimino->figure[0][1]] == '.' && check == 1)
    {
        field = ft_fill(tetrimino, field, p);
        p.x = 0;
        p.y = 0;
		if (tetrimino->next == NULL)
			return (field);
	    return (ft_fill_field(tetrimino->next, field, n, p));
    }
    return (ft_fill_field(tetrimino, field, n, p));
}
