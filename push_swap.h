/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:45:36 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/20 14:27:54 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct 	s_tab
{
	long *tab1;
	long *tab2;
	long *perfect_tab;
	int	index_a;
	int	index_b;
}				t_tab;

typedef struct	s_ope
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}				t_ope;

typedef	struct	s_var
{
	int	pos_first;
	int	pos_last;
	int	count_chunk;
	int	chunk_size;
	int	count_round;
	int	ret_chunk;
	t_ope	ope;
}				t_var;





int	init_tab(int argc, char **argv, t_tab *tabs);
long	ft_atoi(const char *str);
int	ft_isdigit(char *str);
void	sort_int_tab(t_tab *tabs, int size);
void	ft_swap(long *a, long *b);
int	parsing(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
void	swap_a(t_tab *tabs);
void	swap_b(t_tab *tabs);
void	push_a(t_tab *tabs);
void	push_b(t_tab *tabs);
void	rotate_a(t_tab *tabs);
void	rotate_b(t_tab *tabs);
void	reverse_r_a(t_tab *tabs);
void	reverse_r_b(t_tab *tabs);
void	swap_a_b(t_tab *tabs);
void	rotate_a_b(t_tab *tabs);
void	reverse_r_a_b(t_tab *tabs);
int	first_or_last(t_tab *tabs, t_var *var);
int	hold_first(t_tab *tabs, t_var *var);
int	hold_second(t_tab *tabs, t_var *var);
void	ft_bzero(void *s, size_t n);
int	algo(t_tab *tabs, t_var *var);

#endif