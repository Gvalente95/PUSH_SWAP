/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:06:53 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 21:46:50 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_vals_hor(s_pile pile_a, s_pile pile_b)
{
	printf("\n[PILE_A]");
	for (int i = 0; i < pile_a.size -1; i++)
		printf("%d >", pile_a.elems[i].val);
	printf("\n[PILE_B]");
	for (int i = 0; i < pile_b.size -1; i++)
		printf("%d >", pile_b.elems[i].val);
	printf("\n");
	return (0);
}

int	print_vals(s_pile pile_a, s_pile pile_b)
{
	int	i;
	int	a_len;
	int	b_len;

	//return (print_vals_hor(pile_a, pile_b));

	a_len = pile_a.size;
	b_len = pile_b.size;

	if (a_len >= b_len)
		i = a_len - 1;
	else i = b_len - 1;
	while (i >= 0)
	{
		if (i < a_len)
			printf("%d  ", pile_a.elems[i].val);
		else
			printf("   ");
		if (i < b_len)
			printf("%d  ", pile_b.elems[i].val);
		else
			printf("   ");
		printf("\n");
		i--;
	}
	printf("- -\na b\n");
	return (1);
}


int print_info(int debug, char *action)
{
	system("clear");
	const char *debug_modes[] = {"Normal", "Show", "Show++", "graph"};
	printf("DEBUG MODE: %s[%d] | ACTION MODE: %s | ALGO : %s | TEST %d | ARR LEN: %d | INSTR: %d\n", debug_modes[debug], debug, action, func_name, tests, arr_len, instructions_given);
	return (1);
}


void print_piles_state(s_pile pile_a, s_pile pile_b)
{
	int height = 20;
	int width = 60;
	int a_max[2];
	int b_max[2];
	max_value(pile_a, a_max);
	max_value(pile_b, b_max);
	int a_resize = a_max[0] / height + 1;
	int b_resize = b_max[0] / height + 1;

	int a_step = (pile_a.size > width) ? (pile_a.size / width) : 1;
	int b_step = (pile_b.size > width) ? (pile_b.size / width) : 1;

	for (int i = height; i > 0; i--)
	{
		for (int j = 0; j < pile_a.size; j += a_step)
			printf(pile_a.elems[j].val / a_resize >= i ? "a" : ".");
		printf("           ");
		for (int j = 0; j < pile_b.size; j += b_step)
			printf(pile_b.elems[j].val / b_resize >= i ? "b" : ".");
		usleep(50);
		printf("\n");
	}
	//getchar();
}
