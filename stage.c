/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:18:26 by aadlercr          #+#    #+#             */
/*   Updated: 2019/11/12 11:30:10 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(char *str)
{
	char		*board;
	t_tetris	*head;
	int			i;

	head = NULL;
	i = 0;
	board = ft_strnew(BOX_SIZE * BOX_SIZE);
	list_loader(&head, str, &i);
	solve_head(&head, board, sqr_root(i * 4));
	print_board(board);
	return (0);
}
