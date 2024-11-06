/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_selection_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:12:14 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 21:20:37 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_sorted(s_pile pile) {
	int	i;

	i = -1;
    while (++i < pile.size - 1) 
	{
        if (pile.elems[i].val > pile.elems[i + 1].val)
            return 0;
    }
    return 1;
}


int *max_value(s_pile pile, int *values)
{
	int	i;

	i = -1;
	values[0] = -1;
	while (++i < pile.size)
	{
		if (pile.elems[i].val > values[0])
		{
			values[0] = pile.elems[i].val;
			values[1] = i;		
		}
	}
	return (values);
}

int *min_value(s_pile pile, int *values)
{
	int	i;

	i = -1;
	values[0] = 999999999;
	while (++i < pile.size)
	{
		if (pile.elems[i].val < values[0])
		{
			values[0] = pile.elems[i].val;
			values[1] = i;
		}
	}
	return (values);
}

int selection_sort(s_pile *pile_a, s_pile *pile_b)
{
	int split;
	int max[2];
	int operations;
	int direction;

	operations = 0;
	split = pile_a->size;
	while (pile_a->size)
	{
		max_value(*pile_a, max);
		direction = max[1] < pile_a->size / 2 ? -1 : 1;
		while (pile_a->elems[pile_a->size - 1].val != max[0])
			operations += handle_instruction(direction == -1 ? "rra" : "ra", pile_a, pile_b);
		operations += handle_instruction("pb", pile_a, pile_b);
	}
	while (pile_b->size)
	{
		operations += handle_instruction("pa", pile_a, pile_b);
	}
	return (operations);
}

int selection_sort_b(s_pile *pile_a, s_pile *pile_b)
{
	int split;
	int max[2];
	int operations;
	int direction;

	operations = 0;
	split = pile_a->size;
	while (pile_a->size)
	{
		max_value(*pile_a, max);
		direction = max[1] > pile_a->size ? -1 : 1;
		while (pile_a->elems[pile_a->size - 1].val != max[0])
			operations += handle_instruction("ra", pile_a, pile_b);
		operations += handle_instruction("pb", pile_a, pile_b);
	}
	while (pile_b->size)
		operations += handle_instruction("pa", pile_a, pile_b);
	return (operations);
}
