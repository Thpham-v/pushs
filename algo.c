/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:46:29 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/21 17:53:20 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_pos(t_tab *tabs)
{
	int i;
	int bigger;
	int	pos;

	i = 1;
	bigger = tabs->tab2[0];
	while (i < tabs->index_b)
	{
		if (tabs->tab2[i] > bigger)
		{
			bigger = tabs->tab2[i];
			pos = i + 1;
		}
		i++;
	}
	return (pos);
}

int	pos_in_b(t_tab *tabs, int value)
{
	int	i;

	i = 0;
	while (i <= tabs->index_b)
	{
		if (i == 0)
		{
			if (value < tabs->tab2[tabs->index_b - 1] && value > tabs->tab2[i])
				return (i);
		}
		if (value < tabs->tab2[i] && value > tabs->tab2[i + 1])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	first_or_last(t_tab *tabs, t_var *var)
{
	
	var->pos_first = hold_first(tabs, var);
	var->pos_last = hold_second(tabs, var);
	if (var->pos_first == -1 || var->pos_last == -1)
		return (-1);
	if (var->pos_first <= (tabs->index_a - var->pos_last))
		return (1);
	return (2);
}

int	hold_first(t_tab *tabs, t_var *var)
{
	int i;
	int	j;
	 
	i = 0;
	while (i < tabs->index_a)
	{
		j = var->chunk_size * var->count_chunk;
		printf("first = %d\n", j);
		while (j < var->chunk_size * (var->count_chunk + 1))
		{
			if (tabs->tab1[i] == tabs->perfect_tab[j])
			{
				printf("\n");
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	hold_second(t_tab *tabs, t_var *var)
{
	int i;
	int	j;
	
	i = tabs->index_a - 1;
	while (i >= 0)
	{
		j = var->chunk_size * var->count_chunk;
		printf("second = %d\n", j);
		while (j < var->chunk_size * (var->count_chunk + 1))
		{
			if (tabs->tab1[i] == tabs->perfect_tab[j])
			{
				printf("\n");
				return (i);
			}
			j++;
		}
		i--;
	}
	return (-1);
}

void	opti(t_var *var)
{
	if (var->ope.ra >= var->ope.rb)
	{
		var->ope.ra = var->ope.ra - var->ope.rb;
		var->ope.rr = var->ope.rb;
		var->ope.rb = 0;
	}
	else
	{
		var->ope.rb = var->ope.rb - var->ope.ra;
		var->ope.rr = var->ope.ra;
		var->ope.ra = 0;
	}
	if (var->ope.rra >= var->ope.rrb)
	{
		var->ope.rra = var->ope.rra - var->ope.rrb;
		var->ope.rrr = var->ope.rrb;
		var->ope.rrb = 0;
	}
	else
	{
		var->ope.rrb = var->ope.rrb - var->ope.rra;
		var->ope.rrr = var->ope.rra;
		var->ope.rra = 0;
	}
}

void	get_value(t_tab *tabs, t_var *var)
{
	int ret;
	int	pos_b;
	
	ret = first_or_last(tabs, var);
	if (ret == 1)
	{
		var->ope.ra = var->pos_first;
		pos_b = pos_in_b(tabs, tabs->tab1[var->pos_first]);
	}
	if (ret == 2)
	{
		var->ope.rra = tabs->index_a - var->pos_last;
		pos_b = pos_in_b(tabs, tabs->tab1[var->pos_last]);
	}
	if (pos_b == -1)
		pos_b = bigger_pos(tabs);
	if (pos_b <= (tabs->index_b - pos_b))
		var->ope.rb = pos_b;
	else
		var->ope.rrb = tabs->index_b - pos_b;
	//opti(var);
}

void	apply_ope(t_tab *tabs, t_var *var)
{
	while (var->ope.rr-- > 0)
		rotate_a_b(tabs);
	while (var->ope.ra-- > 0)
		rotate_a(tabs);
	while (var->ope.rb-- > 0)
		rotate_b(tabs);
	while (var->ope.rrr-- > 0)
		reverse_r_a_b(tabs);
	while (var->ope.rra-- > 0)
		reverse_r_a(tabs);
	while (var->ope.rrb-- > 0)
		reverse_r_b(tabs);
}

int	algo(t_tab *tabs, t_var *var)
{
	var->count_chunk = 0;
	var->count_round = 1;
	while (tabs->index_a > 9)
	{
		ft_bzero(&var->ope, sizeof(t_ope));
		get_value(tabs, var);
		apply_ope(tabs, var);
		push_b(tabs);
		
		//printf("round = %d\nchunksize = %d\ncount_chunk = %d\n", var->count_round, var->chunk_size, var->count_chunk);
		if (var->count_round == var->chunk_size)
		{
			var->count_chunk++;
			var->count_round = 0;
		}
		var->count_round++;
	}
	return (0);
}