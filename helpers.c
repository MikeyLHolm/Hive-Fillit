/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:05:41 by aadlercr          #+#    #+#             */
/*   Updated: 2019/11/09 12:50:39 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*get_next(t_tetris *head, t_tetris *current)
{
	t_tetris *piece;

	piece = head;
	while (piece->next != head)
	{
		if (piece->place || piece == current)
			piece = piece->next;
		else
			return (piece);
	}
	if (piece->place || piece == current)
		return (0);
	else
		return (piece);
	return (0);
}

void		unset_piece(char **board, t_tetris *piece, int i)
{
	(*board)[i + piece->index1] = '.';
	(*board)[i + piece->index2] = '.';
	(*board)[i + piece->index3] = '.';
	(*board)[i + piece->index4] = '.';
}

void		set_piece(char **board, t_tetris *piece, int i)
{
	(*board)[i + piece->index1] = piece->c;
	(*board)[i + piece->index2] = piece->c;
	(*board)[i + piece->index3] = piece->c;
	(*board)[i + piece->index4] = piece->c;
}

int			check_fit(char **board, t_tetris *piece, int i, int j)
{
	if ((*board)[BOX_SIZE * i + j + piece->index2] != '.')
		return (0);
	if ((*board)[BOX_SIZE * i + j + piece->index3] != '.')
		return (0);
	if ((*board)[BOX_SIZE * i + j + piece->index4] != '.')
		return (0);
	return (1);
}

int			sqr_root(int index)
{
	int counter;

	counter = 0;
	while ((counter++) < 12)
	{
		if ((counter * counter) >= index)
		{
			return (counter);
		}
	}
	return (0);
}
