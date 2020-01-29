/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:33:22 by aadlercr          #+#    #+#             */
/*   Updated: 2019/11/09 14:46:35 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** initializes the board according to the given size, the area in use if the
** solver is marked with '.' everything else is marked with '*'
*/

void		init_board(char **board, int limit)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < BOX_SIZE)
	{
		while (j < BOX_SIZE)
		{
			if (j >= limit || i >= limit)
				(*board)[BOX_SIZE * i + j] = '*';
			else
				(*board)[BOX_SIZE * i + j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** prints the board..
*/

void		print_board(char *board)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < BOX_SIZE)
	{
		while (j < BOX_SIZE)
		{
			if (board[BOX_SIZE * i + j] != '*')
				write(1, &board[BOX_SIZE * i + j], 1);
			j++;
		}
		if (board[BOX_SIZE * i + j] != '*')
			write(1, "\n", 1);
		j = 0;
		i++;
	}
}

/*
** find_next_empty get a piece and a starting index, if it finds a
** place in the array where it can fit the given piece
** after the given starting index.
*/

int			find_next_empty(char *board, t_tetris *piece, int start)
{
	int i;
	int j;

	i = start / BOX_SIZE;
	j = start % BOX_SIZE;
	while (i < BOX_SIZE)
	{
		while (j < BOX_SIZE)
		{
			if (board[BOX_SIZE * i + j] == '.')
			{
				if (check_fit(&board, piece, i, j))
					return (BOX_SIZE * i + j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

/*
** Backtracking solver, returns 0 if it cant be solved with size given if that
** happens solve_head will increase size get_next returns a piece that hasn't
** been placed yet, the linked list is circular because of an earlier versio
** of the algorithm. It might as well be linear but is kept this way for
** learning purposes..
*/

int			solve(t_tetris *head, char *board, int size, int place)
{
	int			i;
	t_tetris	*piece;

	piece = head;
	while ((piece = get_next(head, 0)))
	{
		i = find_next_empty(board, piece, place);
		if (!piece || i == -1)
			return (0);
		else
		{
			set_piece(&board, piece, i);
			piece->place = i + 1;
			if (!solve(piece, board, size, 0))
			{
				unset_piece(&board, piece, i);
				piece->place = 0;
				place = i + 1;
				continue ;
			}
		}
	}
	return (1);
}

/*
** calls solve function increasing the size of the board if it fails
** breaks and returns 1 on successfull completion
** never really returns false since it should always be able to create a board
** of some size if input is correct
*/

int			solve_head(t_tetris **head, char *board, int piecelen)
{
	t_tetris	*current;
	int			i;
	int			size;

	i = 0;
	size = piecelen;
	current = *head;
	init_board(&board, size);
	while (42)
	{
		if (solve(current, board, size, i))
			break ;
		size++;
		init_board(&board, size);
	}
	return (1);
}
