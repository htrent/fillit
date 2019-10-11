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
	while (i * i <= n)
		i++;
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

    getchar();
    printf("%d %d\n", p.y, p.x);
    ft_print_field(field, *n);
    if (field[p.y][p.x] == '.')
    {
        check = ft_check_field(field, tetrimino, p, *n);
        printf("check:%d\n", check);
        if (check == 1)
        {
            field = ft_fill(tetrimino, field, p);
            p.x = 0;
            p.y = 0;
            //ft_print_field(field, *n);
            return (ft_fill_field(tetrimino->next, field, n, p));
        }
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
        if (check > 1)
        {
            if (tetrimino->prev != NULL)
            {
                field = ft_delete_tetrimino(field, tetrimino->prev, &p, *n);
                p.x++;
                ft_print_field(field, *n);
                return (ft_fill_field(tetrimino->prev, field, n, p));
            }
            field = ft_reinit_field(field, check + *n, n);
            return (ft_fill_field(tetrimino, field, n, p));
        }

    }
    else
    {
        if (p.x >= *n)
        {
            p.y++;
            p.x = 0;
        }
        else if (p.x < *n && p.y < *n)
            p.x++;
        else if (tetrimino->prev != NULL)
        {
            field = ft_delete_tetrimino(field, tetrimino->prev, &p, *n);
            p.x = 0
        }
        return (ft_fill_field(tetrimino, field, n, p));
    }
    return (NULL);
	/*t_point	p;
	int check;

	p.x = 0;
	p.y = 0;
	while (p.y < *n)
	{
		while (p.x < *n)
		{
			if (field[p.y][p.x] == '.')
			{
				check = ft_check_field(field, tetrimino, p, *n);
				if (check == 1)
					return (ft_fill(tetrimino, field, p));
				else if (check == -1)
					break ;
				else
					field = ft_reinit_field(field, check, n);
			}
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return (field);*/
}
