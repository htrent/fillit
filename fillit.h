/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:40:45 by hcaterpi          #+#    #+#             */
/*   Updated: 2019/10/01 15:54:20 by htrent           ###   ########.fr       */
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
# define MAX(i, j) (i > j) ? i : j

typedef struct		s_list
{
	int				figure[4][4];
	int				width;
	int				heigth;
	char			alpha;
	struct s_list	*next;
}					t_list;

t_list				*ft_list_create(char *tetrimino);
t_list				*ft_list_add(t_list **begin_list, char *tetrimino);
void    			ft_putchar(char c);
void    			ft_putstr(char *str);
void				ft_shift_upper_left(t_list *head);
int					ft_count_blank_strings(int tetrimino[4][4]);
int					ft_count_blank_columns(int tetrimino[4][4]);
int					**ft_init_field(int counter);
void				ft_print_list(t_list *head);
int					validation(char *tetrimino, int byte_read);
void				display_message(int signal);

void				ft_dimensions_filling(t_list *head);

void				ft_add_alpha(t_list *head);
int					ft_check_field(int **field, char alpha, int i, int j);
void				ft_print_field(int **field, int n);
int					**ft_sum(t_list *tetrimino, int **field, int *n);
int					**ft_reinit_field(int **field, int size, int *n);
#endif
