/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listloader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:36:39 by aadlercr          #+#    #+#             */
/*   Updated: 2019/11/12 11:01:18 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_values(int *num1, int *num2, int *num3, int *num4)
{
	*num1 = -1;
	*num2 = 0;
	*num3 = 0;
	*num4 = -1;
}

/*
** gets as input a list assuming it is valid, creates a circular linked list
** and saves it to the head
*/

void		list_loader(t_tetris **head, char *list, int *count)
{
	int			i;
	int			r;
	int			s;
	int			n;
	t_tetris	*c;

	set_values(&i, &s, &r, &n);
	c = piece_append('A' + (i / 20), head);
	(*count)++;
	while (list[++i])
	{
		if (list[i] == '#')
			(!++n && (s = i) + 1) ? init_piece(n, 0, &c)
			: init_piece(n, (13 * (r - s / 5) + (i % 5) - (s % 5)), &c);
		else if (list[i] == '\n' && ++r)
			if (list[i + 1] == '\n' && list[i + 2])
			{
				c = piece_append('A' + ((i / 20) + 1), head);
				list++;
				n = -1;
				(*count)++;
			}
	}
	c->next = *head;
}
