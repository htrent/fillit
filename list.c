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

void		ft_add_alpha(t_list *head)
{
	t_list	*list;
	int		i;

	i = 0;
	list = head;
	while (list)
	{
		list->alpha = 'A' + i;
		list = list->next;
		i++;
	}
}

t_list		*ft_list_create(char *tetrimino, t_list *prev)
{
	t_list	*current;
	t_point pos;
	int 	temp[4][4];

	current = malloc(sizeof(t_list));
	if (!current)
		return (NULL);
	pos.y = 0;
	pos.x = 0;
	while (*tetrimino)
	{
		if (*tetrimino == '\n')
		{
			pos.y++;
			pos.x = 0;
		}
		else
			temp[pos.y][pos.x++] = (*tetrimino == '#') ? 1 : 0;
		tetrimino++;
	}
	ft_shift_upper_left(temp);
	current = ft_list_create_help(temp, current);
	current->next = NULL;
	current->prev = prev;
	return (current);
}

t_list 	*ft_list_create_help(int temp[4][4], t_list *current)
{
	t_point pos;
	int		fig;

	pos.y = 0;
	pos.x = 0;
	fig = 0;
	while (pos.y < 4)
	{
		while (pos.x < 4)
		{
			if (temp[pos.y][pos.x])
			{
				current->figure[fig][0] = pos.y;
				current->figure[fig++][1] = pos.x;
			}
			pos.x++;
		}
		pos.y++;
		pos.x = 0;
	}
	return (current);
}

t_list		*ft_list_add(t_list **begin_list, char *tetrimino)
{
	t_list *current;

	if (!(*begin_list))
	{
		*begin_list = ft_list_create(tetrimino, NULL);
		current = *begin_list;
	}
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = ft_list_create(tetrimino, current);
		current = current->next;
	}
	return (current);
}

void		ft_print_list(t_list *head)
{
	t_list	*list;
	int		i;
	int		j;
	int 	pos;

	list = head;
	while (list)
	{
		pos = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (list->figure[pos][0] == i && list->figure[pos][1] == j)
				{
					ft_putchar(list->alpha);
					pos++;
				}
				else
					ft_putchar('.');
				j++;
			}
			ft_putchar('\n');
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
