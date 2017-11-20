/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:58:08 by clonger           #+#    #+#             */
/*   Updated: 2017/11/20 16:14:45 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

int			ft_put_tetris(char **tetriminos, char *solution, int y, int i);
int			isValid(char *buf);
char		*ft_set_solution(char **tetriminos);
char		**ft_read(int fd);
void		ft_solve(char **tetriminos, char *solution);
void		ft_init_solution(char *solution, size_t i);
void		reset_solution(char *solution, char alph);
void		ft_parse(char **tetriminos);
void		display(char **tetriminos);
void		error(void);
size_t		ft_valid_form(char *str, size_t i, size_t first);
size_t		ft_check_size(char *str, size_t i);
size_t		ft_nb_tetriminos(char *str);
size_t		ft_enough_char(char *str);
size_t		ft_check_char(char *str);

#endif
