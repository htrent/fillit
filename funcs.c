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

t_list	*ft_shift_upper(t_list *list)
{
	int i;
	int j;
	int shift;

	i = 0;
	j = 0;
	shift = ft_count_blank_columns(list->figure);
	if (shift != 0)
		while (i < 4)
		{
			while (j < 4 - shift)
			{
				list->figure[i][j] = list->figure[i][j + shift];
				list->figure[i][j + shift] = 0;
				j++;
			}
			i++;
			j = 0;
		}
	return (list);
}

t_list	*ft_shift_left(t_list *list)
{
	int i;
	int j;
	int shift;

	i = 0;
	j = 0;
	shift = ft_count_blank_strings(list->figure);
	if (shift != 0)
		while (i < 4 - shift)
		{
			while (j < 4)
			{
				list->figure[i][j] = list->figure[i + shift][j];
				list->figure[i + shift][j] = 0;
				j++;
			}
			j = 0;
			i++;
		}
	return (list);
}

void	ft_shift_upper_left(t_list *head)
{
	t_list *list;

	list = head;
	while (list)
	{
		list = ft_shift_upper(list);
		list = ft_shift_left(list);
		list = list->next;
	}
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

int 	**ft_sum_arrays(t_list *tetrimino, int **field, int i, int j)
{
	int _i;
	int _j;
	int old_j;

	_i = 0;
	_j = 0;
	old_j = j;
	while (_i < tetrimino->heigth)
	{
		while (_j < tetrimino->width)
			field[i][j++] += tetrimino->figure[_i][_j++];
		_j = 0;
		j = old_j;
		_i++;
		i++;
	}
	return (field);
}

int 	**ft_sum(t_list *tetrimino, int **field, int *n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < *n)
	{
		while (j < *n)
		{
			if (!field[i][j])
			{
				if ((i + tetrimino->heigth <= *n) && (j + tetrimino->width <= *n) && ft_check_field(field, tetrimino->alpha, i, j))
					return (ft_sum_arrays(tetrimino, field, i, j));
				else if (j + tetrimino->width > *n && i + tetrimino->heigth <= *n)
					break ;
				else if (i + tetrimino->heigth > *n)
					field = ft_reinit_field(field, MAX(i + tetrimino->heigth, j + tetrimino->width), n);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (field);
}
