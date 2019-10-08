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

int		ft_count_blank_strings(int tetrimino[4][4])
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4 && tetrimino[i][j] == 0)
		{
			j++;
			count++;
		}
		if (j != 4)
			break ;
		j = 0;
		i++;
	}
	return (count / 4);
}

int		ft_count_blank_columns(int tetrimino[4][4])
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4 && tetrimino[j][i] == 0)
		{
			j++;
			count++;
		}
		if (j != 4)
			break ;
		j = 0;
		i++;
	}
	return (count / 4);
}

void 	ft_shift_upper(int temp[4][4])
{
	int i;
	int j;
	int shift;

	i = 0;
	j = 0;
	shift = ft_count_blank_columns(temp);
	if (shift != 0)
		while (i < 4)
		{
			while (j < 4 - shift)
			{
				temp[i][j] = temp[i][j + shift];
				temp[i][j + shift] = 0;
				j++;
			}
			i++;
			j = 0;
		}
}

void 	ft_shift_left(int temp[4][4])
{
	int i;
	int j;
	int shift;

	i = 0;
	j = 0;
	shift = ft_count_blank_strings(temp);
	if (shift != 0)
		while (i < 4 - shift)
		{
			while (j < 4)
			{
				temp[i][j] = temp[i + shift][j];
				temp[i + shift][j] = 0;
				j++;
			}
			j = 0;
			i++;
		}
}

void	ft_shift_upper_left(int temp[4][4])
{
	ft_shift_upper(temp);
	ft_shift_left(temp);
}

void	ft_dimensions_filling(t_list *head)
{
	t_list	*current;
	int		i_max;
	int		j_max;
	int		i;
	int		j;

	current = head;
	while (current)
	{
		i_max = 0;
		j_max = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (current->figure[i][j] == 1)
				{
					i_max = (i > i_max) ? i : i_max;
					j_max = (j > j_max) ? j : j_max;
				}
				j++;
			}
			i++;
		}
		current->width = j_max + 1;
		current->heigth = i_max + 1;
		current = current->next;
	}
}

int 	**ft_sum_arrays(t_list *tetrimino, int **field, t_point p)
{
	t_point _p;
	int old_j;

	_p.y = 0;
	_p.x = 0;
	old_j = p.x;
	while (_p.y < tetrimino->heigth)
	{
		while (_p.x < tetrimino->width)
			field[p.y][p.x++] += tetrimino->figure[_p.y][_p.x++];
		_p.x = 0;
		p.x = old_j;
		_p.y++;
		p.y++;
	}
	return (field);
}

int 	**ft_sum(t_list *tetrimino, int **field, int *n, t_point p)
{
	while (p.y < *n)
	{
		while (p.x < *n)
		{
			if (!field[p.y][p.x])
			{
				if ((p.y + tetrimino->heigth <= *n) && (p.x + tetrimino->width <= *n) && ft_check_field(field, tetrimino, p))
					return (ft_sum_arrays(tetrimino, field, p));
				else if (p.x + tetrimino->width > *n && p.y + tetrimino->heigth <= *n)
					break ;
				else if (p.y + tetrimino->heigth > *n)
					field = ft_reinit_field(field, MAX(p.y + tetrimino->heigth, p.x + tetrimino->width), n);
			}
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	return (field);
}

void 	ft_middle_check(t_list *tetrimino, int **field, int *n)
{
	t_list *tetr;
	t_point p;
	int lim;
	int	st_n;

	p.x = 0;
	p.y = 0;
	tetr = tetrimino;
	lim = *n - (MAX(tetrimino->width, tetrimino->heigth));
	st_n = *n;
	while (p.y < lim)
	{
		while (p.x < lim)
		{
			printf("\n        Solution #%d\n", (p.x + 1) * (p.y + 1));
			while (tetr)
			{
				getchar();
				field = ft_sum(tetr, field, n, p);
				ft_print_field(field, *n);
				ft_putchar('\n');
				tetr = tetr->next;
			}
			ft_free_field(field, *n);
			*n = st_n;
			field = ft_init_field(*n);
			tetr = tetrimino;
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	ft_free_field(field, *n);
}
