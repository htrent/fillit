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

int 	**ft_reinit_field(int **field, int size, int *n)
{
	int **new_field;
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

int		ft_check_field(int **field, t_list *tetrimino, t_point p)
{
	t_point fig;

	fig.y = 0;
	fig.x = 0;
	while (fig.y < 4)
	{
		while (fig.x < 4)
		{
			if (tetrimino->figure[fig.y][fig.x] && field[p.y + fig.y][p.x + fig.x])
				return (0);
			fig.x++;
		}
		fig.x = 0;
		fig.y++;
	}
	return (1);
	/* if ((alpha == 'A' && A(field, p.y, p.x) == 0)
		|| (alpha == 'B' && B(field, p.y, p.x) == 0)
		|| (alpha == 'C' && C(field, p.y, p.x) == 0)
		|| (alpha == 'D' && D(field, p.y, p.x) == 0)
		|| (alpha == 'E' && E(field, p.y, p.x) == 0)
		|| (alpha == 'F' && F(field, p.y, p.x) == 0)
		|| (alpha == 'G' && G(field, p.y, p.x) == 0)
		|| (alpha == 'H' && H(field, p.y, p.x) == 0)
		|| (alpha == 'J' && J(field, p.y, p.x) == 0)
		|| (alpha == 'K' && K(field, p.y, p.x) == 0)
		|| (alpha == 'L' && L(field, p.y, p.x) == 0)
		|| (alpha == 'M' && M(field, p.y, p.x) == 0)
		|| (alpha == 'N' && N(field, p.y, p.x) == 0)
		|| (alpha == 'O' && O(field, p.y, p.x) == 0)
		|| (alpha == 'P' && P(field, p.y, p.x) == 0)
		|| (alpha == 'Q' && Q(field, p.y, p.x) == 0)
		|| (alpha == 'R' && R(field, p.y, p.x) == 0)
		|| (alpha == 'S' && S(field, p.y, p.x) == 0)
		|| (alpha == 'T' && T(field, p.y, p.x) == 0))
			return (1);
	return (0);*/
}

void	ft_print_field(int **field, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{

		while (j < n)
		{
			ft_putchar(field[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_free_field(int **field, int n)
{
	int i;

	if (!field || !*field)
		return ;
	i = 0;
	while (i < n)
		free(field[i++]);
	free(field);
}
