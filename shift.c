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
