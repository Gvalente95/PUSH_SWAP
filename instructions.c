/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:06:59 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 21:48:45 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	swap(s_pile *pile)
{
	int	tmp;

	if (pile->size <= 1)
		return (0);
	tmp = pile->elems[pile->size - 1].val;
	pile->elems[pile->size - 1].val = pile->elems[pile->size - 2].val;
	pile->elems[pile->size - 2].val = tmp;
	return (1);
}

int	put(s_pile *receiver, s_pile *giver)
{
	if (giver->size <= 0)
		return (0);
	receiver->size++;
	receiver->elems[receiver->size - 1].val = giver->elems[giver->size - 1].val;
	giver->elems[giver->size - 1].val = 0;
	giver->size--;
	return (1);
}

int	rotate(s_pile *pile)
{
	int	i;
	int	tmp;
	int	sc_tmp;

	if (pile->size <= 0)
		return (0);
	tmp = pile->elems[0].val;
	pile->elems[0].val = pile->elems[pile->size - 1].val;
	i = 1;
	while (i < pile->size - 1)
	{
		sc_tmp = pile->elems[i].val;
		pile->elems[i].val = tmp;
		tmp = sc_tmp;
		i++;
	}
	pile->elems[i].val = tmp;
	return (1);
}

int	reverse_rotate(s_pile *pile)
{
	int	i;
	int	tmp;
	int	sc_tmp;

	if (pile->size <= 1)
		return (0);
	tmp = pile->elems[pile->size - 1].val;
	pile->elems[pile->size - 1].val = pile->elems[0].val;
	i = pile->size - 2;
	while (i > 0)
	{
		sc_tmp = pile->elems[i].val;
		pile->elems[i].val = tmp;
		tmp = sc_tmp;
		i--;
	}
	pile->elems[i].val = tmp;
	return (1);
}

int	handle_instruction(char *instruction, s_pile *pile_a, s_pile *pile_b)
{
	int res;

	res = -1;
	print_info(debug, "automatic");
	if (!strncmp(instruction, "sa", 2))
		res = swap(pile_a);
	else if (!strncmp(instruction, "sb", 2))
		res = swap(pile_b);
	else if (!strncmp(instruction, "ss", 2))
		res = swap(pile_a) + swap(pile_b);
	else if (!strncmp(instruction, "pa", 2))
		res = put(pile_a, pile_b);
	else if (!strncmp(instruction, "pb", 2))
		res = (put(pile_b, pile_a));
	else if (!strncmp(instruction, "rra", 3))
		res = (reverse_rotate(pile_a));
	else if (!strncmp(instruction, "rrb", 3))
		res = (reverse_rotate(pile_b));
	else if (!strncmp(instruction, "rrr", 3))
		res = (reverse_rotate(pile_a) + reverse_rotate(pile_b));
	else if (!strncmp(instruction, "ra", 2))
		res = (rotate(pile_a));
	else if (!strncmp(instruction, "rb", 2))
		res = (rotate(pile_b));
	else if (!strncmp(instruction, "rr", 2))
		res = (rotate(pile_a) + rotate(pile_b));
	if (res)
		instructions_given++;
	if (debug == 0)
		printf("%s\n", instruction);
	else if (debug == 3)
		print_piles_state(*pile_a, *pile_b);
	else if (debug == 1)
	{
		print_vals(*pile_a, *pile_b);
		char buffer[100];
		if (fgets(buffer, sizeof(buffer), stdin) != NULL)
			debug = buffer[0] == '0' ? 0 : buffer[0] == '1' ? 1 : buffer[0] == '2' ? 2 : buffer[0] == '3' ? 3 : debug;
	}
	else if (debug == 2)
	{
		print_vals(*pile_a, *pile_b);
		usleep(50000);		
	}
	return (res);
}
