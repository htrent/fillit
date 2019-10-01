/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by htrent            #+#    #+#             */
/*   Updated: 2019/10/01 17:41:47 by marvin           ###   ########.fr       */
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

int		**ft_init_field(int n)
{
	int **field;
	int i;
	int j;

	i = -1;
	j = 0;
	field = (int **)malloc(sizeof(int *) * n);
	if (!field)
		return (NULL);
	while (++i < n)
	{
		field[i] = (int *)malloc(sizeof(int) * n);
		if (!field[i])
		{
			while (i >= 0)
				free(field[i--]);
			return (NULL);
		}
		while (j < n)
			field[i][j++] = 0;
		j = 0;
	}
	return (field);
}

int		ft_resolving(int **field)
{
	
	return (0);
}

void	ft_print_map(int **field)
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			ft_putchar(field[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}