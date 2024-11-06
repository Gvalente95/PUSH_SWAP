/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_turk_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:16:21 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 19:25:41 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_op_amount(s_pile *pile_a, s_pile *pile_b)
{
	int values[2];
	int op_amount;

	max_value(*pile_b, values);
	op_amount = 0;
	if (pile_a->elems[pile_a->size - 1].val > values[0])
	{
		op_amount += (pile_b->size - values[1]);
		op_amount += 1;		
	}
	return (op_amount);
}

int turk_sort(s_pile *pile_a, s_pile *pile_b)
{
	system("clear");
	int op_amount;
	handle_instruction("pb", pile_a, pile_b);
	handle_instruction("pb", pile_a, pile_b);
	op_amount = get_op_amount(pile_a, pile_b);
	printf("%d", op_amount);
	print_vals(*pile_a, *pile_b);
	getchar();
	return (1);
}