/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:32:00 by aadlercr          #+#    #+#             */
/*   Updated: 2019/11/12 11:00:28 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BOX_SIZE 13
# define BUFF_SIZE 21

/*
** The struct contains a variable for the index of each node in a tetrimino
** The first index is always 0 and the others are the value added to the
** first indexto get to their respective index in the one dimensional array.
** (Which is BOX_SIZE wide)
** for example:
** .  0  1  .
** .  . 13  .
** .  . 25  .
** .  .  .  .
** so if we want to check if the piece fits in board[5] we only have to add
** the value of each node to that index to get their correct placement on the
** board
*/

typedef struct		s_tetris
{
	int				index1;
	int				index2;
	int				index3;
	int				index4;
	char			c;
	int				place;
	struct s_tetris	*next;
}					t_tetris;

t_tetris			*new_piece(char c);
void				init_piece(int count, int value, t_tetris **piece);
void				set_piece(char **board, t_tetris *piece, int i);
int					check_fit(char **board, t_tetris *piece, int i, int j);
void				unset_piece(char **board, t_tetris *piece, int i);
t_tetris			*get_next(t_tetris *head, t_tetris *current);
void				list_loader(t_tetris **head, char *list, int *count);
t_tetris			*piece_append(char c, t_tetris **head);
int					sqr_root(int index);
void				init_board(char **board, int limit);
void				print_board(char *board);
int					find_next_empty(char *board, t_tetris *piece, int start);
int					solve(t_tetris *head, char *board, int size, int place);
int					solve_head(t_tetris **head, char *board, int piecelen);
int					fillit(char *str);

#endif
