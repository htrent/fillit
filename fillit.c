/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/19 14:01:55 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	if (i * i != n)
		i--;
	return (i);
}

int		init_figures(int n, char *str, t_list **figures)
{
	char	*buffer;
	int		byte_read;
	int		fd;

	if (n != 2 || (fd = open(str, O_RDONLY)) == -1)
		return (1);
	buffer = (char *)malloc(sizeof(char) * 22);
	while ((byte_read = read(fd, buffer, 21)))
	{
		buffer[byte_read] = '\0';
		if (byte_read < 19 || validation(buffer, byte_read))
		{
			free(buffer);
			return (1);
		}
		ft_list_add(figures, buffer);
		(*figures)->place.x = 0;
		(*figures)->place.y = 0;
	}
	if (ft_strlen(buffer) != 20)
	{
		free(buffer);
		return (1);
	}
	free(buffer);
	close(fd);
	return (ft_list_count(*figures));
}

int		main(int argc, char **argv)
{
	t_list	*figures;
	int		count;
	char	**field;
	int		n;
	t_point	p;

	figures = NULL;
	p.x = 0;
	p.y = 0;
	count = init_figures(argc, argv[1], &figures);
	if ((count == 1 || count == 0) && display_message(count))
		return (0);
	ft_add_alpha(figures);
	n = 2 * ft_sqrt(count);
	field = ft_init_field(n);
	while (!ft_fill_field(figures, field, n, p))
	{
		ft_free_field(field, n++);
		field = ft_init_field(n);
	}
	ft_print_field(field, n);
	ft_free_field(field, n);
	ft_clear_list(&figures);
	return (0);
}
