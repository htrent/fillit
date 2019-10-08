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

# define MAX(i, j) (i > j) ? i : j

typedef struct		s_list
{
	int				figure[4][2]; //coordinates of '#'
	int				width;
	int				heigth;
	char			alpha;
	struct s_list	*next;
}					t_list;

typedef	struct		s_point
{
	int 			x;
	int 			y;
}					t_point;

int 				ft_sqrt(int n);

t_list				*ft_list_create(char *tetrimino);
t_list 				*ft_list_create_help(int 	temp[4][4], t_list *current);
t_list				*ft_list_add(t_list **begin_list, char *tetrimino);
void    			ft_putchar(char c);
void    			ft_putstr(char *str);
void				ft_shift_upper_left(int temp[4][4]);
int					ft_count_blank_strings(int tetrimino[4][4]);
int					ft_count_blank_columns(int tetrimino[4][4]);
int					**ft_init_field(int counter);
void				ft_print_list(t_list *head);
int					validation(char *tetrimino, int byte_read);
void				display_message(int signal);

void				ft_dimensions_filling(t_list *head);

void				ft_add_alpha(t_list *head);
int					ft_check_field(int **field, t_list *tetrimino, t_point p);
void				ft_print_field(int **field, int n);
int					**ft_sum(t_list *tetrimino, int **field, int *n, t_point p);
int					**ft_reinit_field(int **field, int size, int *n);
void				ft_free_field(int **field, int n);
void				ft_clear_list(t_list **head);
int 				**ft_sum_arrays(t_list *tetrimino, int **field, t_point p);
void 				ft_middle_check(t_list *tetrimino, int **field, int *n);
#endif
