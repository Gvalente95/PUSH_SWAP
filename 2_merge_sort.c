/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:41:36 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/04 22:08:14 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int merge_sorted_halves(s_pile *pile_a, s_pile *pile_b) {
    int operations = 0;

    while (pile_b->size > 0) 
	{
        if (pile_a->size == 0 || pile_a->elems[pile_a->size - 1].val <= pile_b->elems[pile_b->size - 1].val)
            operations += handle_instruction("pa", pile_a, pile_b);
        else
            operations += handle_instruction("ra", pile_a, pile_b);
    }
    while (!is_sorted(*pile_a))
        operations += handle_instruction("ra", pile_a, pile_b);
    return operations;
}

int merge_sort_split(s_pile *pile_a, s_pile *pile_b, int size) 
{
	int	i;
    int operations;
	int half_size;

	operations = 0;
    if (size <= 1)
        return operations;

    half_size = size / 2;
	i = -1;
    while(++i < half_size)
        operations += handle_instruction("pb", pile_a, pile_b);
    operations += merge_sort_split(pile_a, pile_b, size - half_size); // Sort remaining half in pile_a
    operations += merge_sort_split(pile_b, pile_a, half_size);        // Sort half in pile_b
    //operations += merge_sorted_halves(pile_a, pile_b);
    return operations;
}

int merge_sort(s_pile *pile_a, s_pile *pile_b) 
{
    return merge_sort_split(pile_a, pile_b, pile_a->size);
}