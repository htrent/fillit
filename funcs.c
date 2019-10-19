/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:28:27 by htrent            #+#    #+#             */
/*   Updated: 2019/10/18 13:28:30 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_max(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

void	ft_add_alpha(t_list *head)
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
