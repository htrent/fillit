/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:21:53 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/25 16:33:19 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void        ft_print_list(t_list *head)
{
    t_list *list;
    int i;
    int j;

    list = head;
    while (list)
    {
        i = 0;
        j = 0;
        while (i < 4)
        {
            while (j < 4)
            {
                ft_putchar(list->figure[i][j++]);
                ft_putchar(' ');
            }
            ft_putchar('\n');
            j = 0;
            i++;
        }
        list = list->next;
    }
}