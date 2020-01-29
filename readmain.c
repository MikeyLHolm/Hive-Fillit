/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadlercr <aadlercr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:53:38 by mlindhol          #+#    #+#             */
/*   Updated: 2019/11/12 11:46:45 by aadlercr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_index(char *str, int *hashtag, int *neighbour, int *point)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '.')
			(*point)++;
		if (str[i] == '#')
		{
			if (i < 14 && str[i + 5] == '#')
				(*neighbour)++;
			if (i >= 5 && str[i - 5] == '#')
				(*neighbour)++;
			if (i >= 1 && str[i - 1] == '#')
				(*neighbour)++;
			if (i < 19 && str[i + 1] == '#')
				(*neighbour)++;
			(*hashtag)++;
		}
		i++;
	}
	return (0);
}

int			verify_tetriminos(char *str)
{
	int		hashtag;
	int		neighbour;
	int		point;

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' ||
		str[19] != '\n' || (str[20] != '\n' && str[20] != '\0'))
		return (-1);
	hashtag = 0;
	neighbour = 0;
	point = 0;
	check_index(str, &hashtag, &neighbour, &point);
	if ((point != 12 || hashtag != 4) || neighbour < 6)
		return (-1);
	return (1);
}

int			read_file(const int fd)
{
	int		n_of_tetriminos;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;

	n_of_tetriminos = 0;
	if (!(str = ft_strnew(1)))
		exit(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (verify_tetriminos(buf) < 0)
			return (-1);
		n_of_tetriminos++;
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	if (ret < 0 || n_of_tetriminos < 1 || n_of_tetriminos > 26 ||
	(int)ft_strlen(str) > (n_of_tetriminos * 21) - 1)
		return (-1);
	fillit(str);
	free(str);
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	int		ret;

	ret = 0;
	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(1);
	}
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			write(2, "error\n", 6);
			exit(1);
		}
		ret = read_file(fd);
		if (ret == -1)
		{
			write(2, "error\n", 6);
			exit(1);
		}
	}
	return (0);
}
