/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrent <htrent@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by htrent            #+#    #+#             */
/*   Updated: 2019/09/24 14:42:44 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while(*str)
        ft_putchar(*(str++));
}

int count_blank_strings(int **tetrimino)
{
    int i;
    int j;
    int count;

    while (i < 4)
    {
        while (j < 4 && tetrimino[i][j++] == 0)
            count++;
        if (j != 4)
            break ;
        j = 0;
        i++;
    }
    return (count / 4);
}

int count_blank_columns(int **tetrimino)
{
    int i;
    int j;
    int count;

    while (i < 4)
    {
        while (j < 4 && tetrimino[j++][i] == 0)
            count++;
        if (j != 4)
            break ;
        j = 0;
        i++;
    }
    return (count / 4);
}

void shift_upper_left(t_list *head)
{
    t_list *list;
    int i;
    int j;
    int shift_x;
    int shift_y;

    i = -1;
    j = -1;
    list = head;
    while (list)
    {
        shift_x = count_blank_strings(list->figure);
        while (++i < 4 - shift_x)
            while (++j < 4)
                list->figure[i][j] = list->figure[i + shift_x][j];
         i = -1;
         j = -1;
         shift_y = count_blank_columns(list->figure);
        while (++i < 4)
            while (++j < 4 - shift_y)
                list->figure[i][j] = list->figure[i][j + shift_y];
        list = list->next;
    }
}



int **init_field(int counter)
{
    int n;
    int **field;
    int i;
    int j;

    n = sqrt(counter * 4);
    i = -1;
    j = 0;
    field = (int **)malloc(sizeof(int *) * n);
    if (!field)
        return (NULL);
    while(++i < n)
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

/* **sum_arrays(int **arr1, int n, int **arr2, int m)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < n)
}*/