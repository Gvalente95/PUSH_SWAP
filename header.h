/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:55:11 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 20:47:31 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
#include "test.h"

typedef struct t_element
{
	int	val;
} s_element;

typedef struct t_pile
{
	int			size;
	s_element	elems[9999];
}	s_pile;

int		handle_instruction(char *instruction, s_pile *pile_a, s_pile *pile_b);
char 	**smart_algorithm(s_pile *pile_a, s_pile *pile_b);
int		brute_force(s_pile *pile_a, s_pile *pile_b);
void	manual_play(s_pile *pile_a, s_pile *pile_b);
int		print_vals(s_pile pile_a, s_pile pile_b);
int		print_vals_hor(s_pile pile_a, s_pile pile_b);
int 	print_info(int debug, char *action);

int 	is_sorted(s_pile pile);
void 	print_piles_state(s_pile pile_a, s_pile pile_b);
int 	*max_value(s_pile pile, int *values);
int 	*min_value(s_pile pile, int *values);

int 	selection_sort(s_pile *pile_a, s_pile *pile_b);
int 	selection_sort_b(s_pile *pile_a, s_pile *pile_b);
int 	merge_sort(s_pile *pile_a, s_pile *pile_b);
int 	radix_sort(s_pile *pile_a, s_pile *pile_b);
int 	turk_sort(s_pile *pile_a, s_pile *pile_b);

# endif