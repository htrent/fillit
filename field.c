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

char 	**ft_reinit_field(char **field, int size, int *n)
{
	char **new_field;
	int i;
	int j;

	i = 0;
	j = 0;
	new_field = ft_init_field(size);
	while (i < *n)
	{
		while (j < *n)
		{
			new_field[i][j] = field[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < *n)
		free(field[i++]);
	free(field);
	*n = size;
	return (new_field);
}

int		ft_check_field(char **field, t_list *tetrimino, t_point p, int n)
{
	int pos;
	t_point max;

	pos = 0;
	max.x = 0;
	max.y = 0;
	while (pos < 4)
	{
		max.y = MAX(tetrimino->figure[pos][0], max.y);
		max.x = MAX(tetrimino->figure[pos][1], max.x);
		pos++;
	}
	if (p.x + max.x > n && p.y + max.y <= n)
		return (-1);
	if (p.y + max.y > n && p.x + max.x > n)
		return (MAX(p.y + max.y - n + 1, p.x + max.x - n + 1));
	pos = 0;
	while (pos < 4)
	{
		if (field[p.y + tetrimino->figure[pos][0]][p.x + tetrimino->figure[pos][1]] != '.')
			return (0);
		pos++;
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
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
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
