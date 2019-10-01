/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/01 17:41:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int argv, char **argc)
{
	char	*buffer;
	int		byte_read;
	int		**field;
	int		counter;
	int		size;
	int		fd;

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
		close(fd);
	}
	else
		display_message(0);
	ft_shift_upper_left(g_figures);
	ft_dimensions_filling(g_figures);
	size = ceil(sqrt(counter * 4));
	field = ft_init_field(size);
	while (!ft_resolving(field))
	{
		size++;									// free_map
		field = ft_init_field(size);
	}
	ft_print_map(field);
	//ft_print_list(g_figures);
	return (0);
}
