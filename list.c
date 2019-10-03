/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:21:53 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/03 10:54:59 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_alpha_parse(int figure[4][4])
{
	if (A(figure, 0, 0) == 4)
		return ('A');
	if (B(figure, 0, 0) == 4)
		return ('B');
	if (C(figure, 0, 0) == 4)
		return ('C');
	if (D(figure, 0, 0) == 4)
		return ('D');
	if (E(figure, 0, 0) == 4)
		return ('E');
	if (F(figure, 0, 0) == 4)
		return ('F');
	if (G(figure, 0, 0) == 4)
		return ('G');
	if (H(figure, 0, 0) == 4)
		return ('H');
	if (J(figure, 0, 0) == 4)
		return ('J');
	if (K(figure, 0, 0) == 4)
		return ('K');
	if (L(figure, 0, 0) == 4)
		return ('L');
	if (M(figure, 0, 0) == 4)
		return ('M');
	if (N(figure, 0, 0) == 4)
		return ('N');
	if (O(figure, 0, 0) == 4)
		return ('O');
	if (P(figure, 0, 0) == 4)
		return ('P');
	if (Q(figure, 0, 0) == 4)
		return ('Q');
	if (R(figure, 0, 0) == 4)
		return ('R');
	if (S(figure, 0, 0) == 4)
		return ('S');
	if (T(figure, 0, 0) == 4)
		return ('T');
	return (0);
}

void		ft_add_alpha(t_list *head)
{
	t_list *list;

	list = head;
	while (list)
	{
		list->alpha = ft_alpha_parse(list->figure);
		list = list->next;
	}
}

t_list		*ft_list_create(char *tetrimino)
{
	t_list	*current;
	int		i;
	int		j;

	current = malloc(sizeof(t_list));
	if (current)
	{
		i = 0;
		j = 0;
		while (*tetrimino)
		{
			if (*tetrimino == '\n')
			{
				i++;
				j = 0;
			}
			else
				current->figure[i][j++] = (*tetrimino == '#') ? 1 : 0;
			tetrimino++;
		}
		current->next = NULL;
	}
	return (current);
}

t_list		*ft_list_add(t_list **begin_list, char *tetrimino)
{
	t_list *current;

	if (!(*begin_list))
	{
		*begin_list = ft_list_create(tetrimino);
		current = *begin_list;
	}
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = ft_list_create(tetrimino);
		current = current->next;
	}
	return (current);
}

void		ft_print_list(t_list *head)
{
	t_list	*list;
	int		i;
	int		j;

	list = head;
	while (list)
	{
		i = 0;
		j = 0;
		while (i < 4)
		{
			while (j < 4)
			{
				ft_putchar(list->figure[i][j] + '0');
				ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			j = 0;
			i++;
		}
		ft_putchar('\n');
		list = list->next;
	}
}

void		ft_clear_list(t_list **head)
{
	t_list *to_clear;

	if (!head || !*head)
		return ;
	while (*head)
	{
		to_clear = *head;
		*head = (*head)->next;
		free(to_clear);
	}
}
