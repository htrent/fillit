/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaterpi <hcaterpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/09/25 16:30:45 by hcaterpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include <stdio.h>		// testing
# include <math.h>      // for sqrt

typedef struct	s_list
{
	int				figure[4][4];
	int				width;
	int				heigth;
	struct s_list	*next;
}				t_list;

t_list *ft_list_create(char *tetrimino);
t_list *ft_list_add(t_list **begin_list, char *tetrimino);

int validation(char *tetrimino, int byte_read);
void	display_message(int signal);

#endif