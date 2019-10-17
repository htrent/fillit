/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:56:20 by htrent            #+#    #+#             */
/*   Updated: 2019/10/03 11:15:42 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_init_field(int n)
{
	char **field;
	int i;
	int j;

	i = -1;
	j = 0;
	field = (char **)malloc(sizeof(char *) * n);
	if (!field)
		return (NULL);
	while (++i < n)
	{
		field[i] = (char *)malloc(sizeof(char) * n);
		if (!field[i])
		{
			while (i >= 0)
				free(field[i--]);
			return (NULL);
		}
		while (j < n)
			field[i][j++] = '.';
		j = 0;
	}
	return (field);
}

int		ft_check_field(char **field, t_list *tetrimino, t_point *p, int n)
{
	int pos;

    pos = -1;
	if (p->x + tetrimino->max.x > n && p->y + tetrimino->max.y < n)
	{
	    p->y++;
	    p->x = 0;
        return (-1);
    }
	if (p->y + tetrimino->max.y >= n || (p->y + tetrimino->max.y >= n && p->x + tetrimino->max.x >= n))
		return (2);
	while (++pos < 4)
		if (field[p->y + tetrimino->figure[pos][0]][p->x + tetrimino->figure[pos][1]] != '.')
		{
		    p->x++;
            return (0);
        }
	return (1);
}

void	ft_print_field(char **field, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < n)
		{
			ft_putchar(field[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

char    **ft_delete_tetrimino(char **field, t_list *tetrimino, t_point *p, int n)
{
    p->x = tetrimino->place.x;
    p->y = tetrimino->place.y;
    field[tetrimino->figure[0][0] + tetrimino->place.y][tetrimino->figure[0][1] + tetrimino->place.x] = '.';
    field[tetrimino->figure[1][0] + tetrimino->place.y][tetrimino->figure[1][1] + tetrimino->place.x] = '.';
    field[tetrimino->figure[2][0] + tetrimino->place.y][tetrimino->figure[2][1] + tetrimino->place.x] = '.';
    field[tetrimino->figure[3][0] + tetrimino->place.y][tetrimino->figure[3][1] + tetrimino->place.x] = '.';
	if (p->x >= n - 1)
	{
		p->x = 0;
		p->y++;
	}
	else
	    p->x++;
    return (field);
}

void	ft_free_field(char **field, int n)
{
	int i;

	if (!field || !*field)
		return ;
	i = 0;
	while (i < n)
		free(field[i++]);
	free(field);
}
