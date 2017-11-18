/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:58:08 by clonger           #+#    #+#             */
/*   Updated: 2017/11/07 17:58:11 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

size_t		ft_check_char(char *str);
size_t		ft_check_size(char *str);
size_t		ft_nb_tetriminos(char *str);
size_t		ft_enough_char(char *str);
size_t		ft_valid_form(char *str, size_t i);
size_t		ft_count(char *str, size_t (f)(char *, size_t i));
void		display(char **tetriminos);
int			isValid(char *buf);
char		**ft_read(int fd);
void		error(void);
void		ft_parse(char **tetriminos);
void		ft_put_tetris(char **tetriminos, char *solution, int y, int i);
void		ft_set_solution(char *solution, char **tetriminos, int y);
char		ft_find_alph(char *tetriminos);
void		reset_tetriminos(char *solution, char alph);

#endif
