/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_radix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:39:44 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 18:18:04 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int get_max_bits(int max_value)
{
    int bits = 0;
    while (max_value > 0) {
        max_value >>= 1;
        bits++;
    }
    return bits;
}

int radix_sort(s_pile *pile_a, s_pile *pile_b) 
{
    int values[2];
    max_value(*pile_a, values);
    int max_bits = get_max_bits(values[0]);
    int i, j;

    for (i = 0; i < max_bits; i++) {
        int size = pile_a->size;
        for (j = 0; j < size; j++) {
            int num = pile_a->elems[0].val;
            if ((num >> i) & 1) {
                handle_instruction("pb", pile_a, pile_b);  // Bit `i` is 1
            } else {
                handle_instruction("ra", pile_a, pile_b);  // Bit `i` is 0
            }
        }
        while (pile_b->size > 0) {
            handle_instruction("pa", pile_a, pile_b);
        }
    }
	return (1);
}