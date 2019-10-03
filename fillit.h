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
# define A(f, i, j) f[i][j] + f[i + 1][j] + f[i + 2][j] + f[i + 3][j]
# define B(f, i, j) f[i][j] + f[i][j + 1] + f[i][j + 1] + f[i][j + 2]
# define C(f, i, j) f[i][j] + f[i][j + 1] + f[i + 1][j] + f[i + 1][j + 1]
# define D(f, i, j) f[i][j] + f[i + 1][j] + f[i + 2][j] + f[i + 2][j + 1]
# define E(f, i, j) f[i][j + 2] + f[i + 1][j] + f[i + 1][j + 2] + f[i + 1][j + 3]
# define F(f, i, j) f[i][j] + f[i][j + 1] + f[i + 1][j + 1] + f[i + 2][j + 1]
# define G(f, i, j) f[i][j] + f[i][j + 1] + f[i][j + 2] + f[i + 1][j]
# define H(f, i, j) f[i][j] + f[i + 1][j] + f[i + 1][j + 1] + f[i + 2][j + 1]
# define J(f, i, j) f[i][j + 1] + f[i][j + 2] + f[i + 1][j] + f[i + 1][j + 1]
# define K(f, i, j) f[i][j] + f[i + 1][j] + f[i + 2][j] + f[i + 1][j + 1]
# define L(f, i, j) f[i][j + 1] + f[i + 1][j] + f[i + 1][j + 1] + f[i + 1][j + 2]
# define M(f, i, j) f[i][j + 1] + f[i + 1][j] + f[i + 1][j + 1] + f[i + 2][j + 1]
# define N(f, i, j) f[i][j] + f[i][j + 1] + f[i][j + 2] + f[i + 1][j + 1]
# define O(f, i ,j) f[i][j + 1] + f[i + 1][j + 1] + f[i + 2][j] + f[i + 2][j + 1]
# define P(f, i, j) f[i][j] + f[i + 1][j] + f[i + 1][j + 1] + f[i + 1][j + 2]
# define Q(f, i ,j) f[i][j] + f[i][j + 1] + f[i + 1][j] + f[i + 2][j]
# define R(f, i, j) f[i][j] + f[i][j + 1] + f[i][j + 2] + f[i + 1][j + 2]
# define S(f, i, j) f[i][j + 1] + f[i + 1][j] + f[i + 1][j + 1] + f[i + 2][j]
# define T(f, i, j) f[i][j] + f[i][j + 1] + f[i + 1][j + 1] + f[i + 1][j + 2]

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
void				ft_free_field(int **field, int n);
void				ft_clear_list(t_list **head);
int 				**ft_sum_arrays(t_list *tetrimino, int **field, int i, int j);
#endif
