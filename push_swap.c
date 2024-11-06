/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalente <gvalente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:55:42 by gvalente          #+#    #+#             */
/*   Updated: 2024/11/05 18:31:49 by gvalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_error()
{
	write(2, "Error\n", 6);
	return (0);
}

int	is_arg_valid(char *arg, s_pile pile, int index)
{
	int		i;
	int		res;

	i = 0;
	while (arg[i])
		if (!ft_isdigit(arg[i++]))
			return (0);
	if (i > 10)
		return (0);
	res = ft_atoi(arg);
	if (res < 0)
		return (-1);
	pile.elems[index--].val = res;
	while (index >= 0)
		if (pile.elems[index--].val == res)
			return (0);
	return (res);
}

int main(int argc, char *argv[])
{
	int		i;
	s_pile 	pile_a;
	s_pile 	pile_b;

	i = 0;
	pile_a.size = 0;
	pile_b.size = 0;
	if (argc <= 1)
		return (0);
	debug = ft_atoi(argv[1]);
	// while (argc > 1)
	// {
	// 	if (!is_arg_valid(argv[argc - 1], pile_a, argc - 1))
	// 		return (print_error());
	// 	pile_a.elems[i++].val = ft_atoi(argv[--argc]);
	// 	pile_a.size++;
	// }
	return (0);
}
