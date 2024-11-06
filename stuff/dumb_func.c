#include "header.h"


char **smart_algorithm(s_pile *pile_a, s_pile *pile_b)
{
	char	*new_command;
	char	**instructions;
	int		num_tries;
	int		max_tries;
	int		i;

	srand(0);
	max_tries = 30000000;
	instructions = malloc(max_tries * sizeof(char *));
	for (i = 0; i < max_tries; i++)
		instructions[i] = malloc(4 * sizeof(char));
	num_tries = -1;
	while (++num_tries < max_tries)
	{
		if (is_sorted(*pile_a) && pile_b->size == 0)
			break;
		new_command = choose_command(pile_a, pile_b);
		i = -1;
		while (new_command[++i])
			instructions[num_tries][i] = new_command[i];
		instructions[num_tries][i] = '\0';
		handle_instruction(instructions[num_tries], pile_a, pile_b);
	}
	instructions[num_tries] = NULL;
	return (instructions);
}

int brute_force(s_pile *pile_a, s_pile *pile_b)
{
	char *commands[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rr", "rb", "rra", "rrb", "rrr"};
	int tries = 0;
	int max_tries = 8000;
	srand(0);

	while (tries < max_tries)
	{
		system("clear");
		print_vals(*pile_a, *pile_b);
		if (is_sorted(*pile_a) && pile_b->size == 0)
		{
			printf("num tries: %d\n", tries);
			return(1);
		}
		handle_instruction(commands[rand() % 10], pile_a, pile_b);
		tries++;
		//getchar();
	}
	printf("num tries: %d\n", tries);
	return (0);
}
