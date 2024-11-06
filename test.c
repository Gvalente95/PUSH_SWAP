/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:57:30 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 21:43:47 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <time.h>

int	is_in_val(s_pile pile, int val)
{
	int i;

	i = -1;
	while (++i < pile.size)
	{
		if (pile.elems[i].val == val)
			return (1);
	}
	return (0);
}

void	populate_pile(s_pile *pile, int amount)
{
	int i;

	i = -1;
	pile->size = 0;
	while (++i < amount)
	{
		int new_val = 1 + rand() % (amount + 6);
		while (is_in_val(*pile, new_val))
			new_val = 1 + rand() % (amount + 6);
		pile->elems[i].val = new_val;
		pile->size++;
	}
}
void	copy_pile(s_pile *pile_a, s_pile *copy)
{
	int i = -1;

	copy->size = 0;
	while (++i < pile_a->size)
	{
		copy->elems[i].val = pile_a->elems[i].val;
		copy->size++;
	}
}

void set_new_mode(s_pile *a, s_pile *b)
{
	char buffer[100];
	if (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		int prv_deb = debug;
		debug = buffer[0] == '0' ? 0 : buffer[0] == '1' ? 1 : buffer[0] == '2' ? 2 : buffer[0] == '3' ? 3 : debug;
		if (prv_deb != debug)
			print_info(debug, "automatic");
		if (handle_instruction(buffer, a, b) != -1)
			manual_play(a, b);
	}
}

int test(int amount, s_pile *pile_a, s_pile *pile_b, int (*f)(s_pile *, s_pile *))
{
	s_pile tmp_a, tmp_b;
	int final_max = 0;
	int	result;

	tmp_b.size = 0;
	result = 0;
	instructions_given = 0;
	for (int i = 0; i < TESTS_AMOUNT; i++)
	{
		tests = i;
		populate_pile(pile_a, amount);
		copy_pile(pile_a, &tmp_a);
		result = f(pile_a, pile_b);
		final_max += result;
		if (!is_sorted(*pile_a) || pile_b->size != 0)
			return (-1);	
		print_info(debug, "Auto");
	}
	print_info(debug, "Auto");
	printf("SUCCESS : ARR LEN: %d | AVRG INSTRUCTIONS: %d | TESTS : %d", amount, final_max / TESTS_AMOUNT, TESTS_AMOUNT);
	set_new_mode(pile_a, pile_b);
	return (1);
}

void manual_play(s_pile *pile_a, s_pile *pile_b)
{
	system("clear");
	int prv_debug = debug;
    char buffer[100];

    debug = 0;
    while (1)
    {
		print_info(debug, "MANUAL");
        print_vals(*pile_a, *pile_b);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
			if (buffer[0] == 'q')
				break;
            handle_instruction(buffer, pile_a, pile_b);
        }
    	system("clear");
    }
	debug = prv_debug;
}

int debug = 1;
int (*functions[])(s_pile *, s_pile *) = {radix_sort, selection_sort, merge_sort, turk_sort};
char *function_names[] = {"radix", "sel_sort", "merge", "turk"};
char *func_name;
int tests;
int arr_len = 6;
int instructions_given;

int main(int argc, char *argv[])
{
	s_pile pile_a, pile_b;
	int res;
	int (*f)(s_pile *, s_pile *) = functions[0];
	func_name = function_names[0];
	srand(time(NULL));

	res = 0;
	if (argc > 2)
		debug = ft_atoi(argv[2]);
	if (argc > 1)
	{
		for (int i = 0; i < 4; i++)
			if (strncmp(argv[1], function_names[i], 1) == 0)
			{
				f = functions[i];
				printf("   Welcome\n   TESTING: %s\n", function_names[i]);
				func_name = function_names[i];	
				break;
			}
	}
	else
		printf("   Welcome\n   TESTING: %s\n(Usage: ./a.out \"name of algorithm\" \"debug_mode\" ", function_names[0]);
	while (arr_len <= 99999)
	{
		pile_a.size = pile_b.size = 0;
		res = test(arr_len, &pile_a, &pile_b, f);
		if (arr_len * 2 <= 2000)
			system("clear");
		arr_len *= 2;
        set_new_mode(&pile_a, &pile_b);
	}
    return 0;
}