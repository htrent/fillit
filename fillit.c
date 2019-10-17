/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/01 16:22:56 by htrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*g_figures;

int		main(int argv, char **argc)
{
	char	*buffer;
	int		byte_read;
	int		counter;
	int		fd;

	char **field;
	int n;
	t_point p;

	if (argv == 2)
	{
		if ((fd = open(argc[1], O_RDONLY)) == -1)
		{
			display_message(1);
			return (1);
		}
		counter = 0;
		buffer = (char *)malloc(sizeof(char) * 22);
		while ((byte_read = read(fd, buffer, 21)))
		{
			buffer[byte_read] = '\0';
			if (validation(buffer, byte_read))
			{
				display_message(1);
				return (1);
			}
			ft_list_add(&g_figures, buffer);
			counter++;
		}
		if (strlen(buffer) != 20 || counter < 2 || counter > 25)///_ft_strlen!!!
		{
			display_message(1);
			return (1);
		}
		free(buffer);
		close(fd);
	}
	else
	{
		display_message(0);
		return (1);
	}
	ft_add_alpha(g_figures);
 //	ft_print_list(g_figures);
	n = 2 * ft_sqrt(counter);
	field = ft_init_field(n);
	p.x = 0;
	p.y = 0;
	while (!ft_fill_field(g_figures, field, n, p))
	{
		ft_free_field(field, n++);
		field = ft_init_field(n);
	}
	ft_print_field(field, n);
	ft_free_field(field, n);
	ft_clear_list(&g_figures);
	return (0);
}
