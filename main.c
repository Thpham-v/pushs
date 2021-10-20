/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:48:14 by thpham-v          #+#    #+#             */
/*   Updated: 2021/10/20 19:00:00 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_tab	tabs;
	t_var	var;

	i = 0;
	var.chunk_size = 5;
	if (parsing(argc, argv) == -1 || init_tab(argc, argv, &tabs) == -1)
		return (1);
	algo(&tabs, &var);
	while (i < argc - 1)
	{
		printf("perfect = %ld\n", tabs.perfect_tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < tabs.index_a)
	{
		printf("tab1 = %ld\n", tabs.tab1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < tabs.index_b)
	{
		printf("tab2 = %ld\n", tabs.tab2[i]);
		i++;
	}

	
	return (0);
}
