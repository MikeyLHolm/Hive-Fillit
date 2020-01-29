/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:11 by aadlercr          #+#    #+#             */
/*   Updated: 2019/11/09 12:52:04 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*new_piece(char c)
{
	t_tetris *new;

	if ((new = (t_tetris *)malloc(sizeof(t_tetris))))
	{
		ft_bzero(new, sizeof(*new));
		new->c = c;
	}
	else
		exit(-1);
	return (new);
}

void		init_piece(int count, int value, t_tetris **piece)
{
	if (count == 0)
		(*piece)->index1 = value;
	else if (count == 1)
		(*piece)->index2 = value;
	else if (count == 2)
		(*piece)->index3 = value;
	else
		(*piece)->index4 = value;
}

t_tetris	*piece_append(char c, t_tetris **head)
{
	t_tetris *ptr;
	t_tetris *prev;
	t_tetris *new;

	new = new_piece(c);
	ptr = *head;
	if (!ptr)
	{
		*head = new;
		return (new);
	}
	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = new;
	return (new);
}
