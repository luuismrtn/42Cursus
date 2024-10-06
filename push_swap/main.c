/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:39:53 by lumartin          #+#    #+#             */
/*   Updated: 2024/10/06 13:08:06 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int argc, char **argv)
{
	t_stack	*stack;
	size_t	i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = argc - 1;
	stack->array = (long *)malloc(sizeof(long) * stack->size);
	if (!stack->array)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		stack->array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

void print_stack(t_stack *stack)
{
    size_t	i;

    i = 0;
    printf("[");
    while (i < stack->size)
    {
        printf("%i, ", stack->array[i]);
        i++;
    }
    printf("]\n");
}

int	check_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push(t_stack *stackA, t_stack *stackB, char c)
{
	int	tmp;
	size_t	i;

	if (stackB->size < 1)
		return ;
	i = stackA->size;
	while (i > 0)
	{
		stackA->array[i] = stackA->array[i - 1];
		i--;
	}
	stackA->array[0] = stackB->array[0];
	i = 0;
	while (i < stackB->size - 1)
	{
		stackB->array[i] = stackB->array[i + 1];
		i++;
	}
	stackB->size--;
	ft_printf("p%c\n", c);
}

void	swap(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	ft_printf("s%c\n", c);
}

void	rotate(t_stack *stack, char c)
{
	int	tmp;
	size_t	i;

	if (stack->size < 2)
		return ;
	i = 0;
	tmp = stack->array[0];
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack *stack, char c)
{
	long	tmp;
	size_t	i;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	tmp = stack->array[i];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = tmp;
	ft_printf("rr%c\n", c);
}

void	sort(t_stack *stackA, t_stack *stackB)
{
	size_t	i;
    int min;
    int max;

    i = 0;
    while (i < stackA->size)
    {
        if (stackA->array[i] < min)
            min = stackA->array[i];
        if (stackA->array[i] > max)
            max = stackA->array[i];
        i++;
    }
	i = 0;
	while (i < stackA->size && !check_sorted(stackA))
	{
		while (i < stackA->size && !check_sorted(stackA))
		{
			if (stackA->array[0] < stackA->array[1] || (stackA->array[1] == min && stackA->array[0] == max))
                rotate(stackA, 'a');
            else
                swap(stackA, 'a');
			i++;
		}
		i = 0;
	}
}

int check_duplicated(t_stack *stack)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < stack->size)
    {
        j = i + 1;
        while (j < stack->size)
        {
            if (stack->array[i] == stack->array[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
int print_error(void)
{
    ft_printf("Error\n");
    return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = stack_init(argc, argv);
	stack_b = stack_init(argc, argv);
	if (!stack_a || !stack_b)
		return (0);
	if (stack_a->size == 1)
		return (print_error());
    if (check_duplicated(stack_a))
        return (0);
	sort(stack_a, stack_b);
	return (0);
}

/*

ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker_linux $ARG

- sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si hay uno o menos elementos.
- sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si hay uno o menos elementos.
- ss swap a y swap b a la vez.
- pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
- pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.
- ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
- rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
	de forma que el primer elemento se convierte en el último.
- rr ra y rb al mismo tiempo.
- rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una posición,
	de forma que el último elemento se convierte en el primero.
- rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una posición,
	de forma que el último elemento se convierte en el primero.
- rrr rra y rrb al mismo tiempo.



*/