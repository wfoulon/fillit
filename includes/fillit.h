/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <clonger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:58:08 by clonger           #+#    #+#             */
/*   Updated: 2017/11/24 14:35:11 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

int			ft_put_tetris(char **tetriminos, char *solution, int y, int i);
char		*ft_set_solution(char **tetriminos);
char		*ft_solve(char **tetriminos);
char		**ft_read(int fd, int j);
void		ft_init_solution(char *solution, int i);
void		reset_all_tetriminos(char **tetriminos);
void		reset_tetriminos(char *tetriminos);
void		ft_parse(char **tetriminos);
void		ft_free(char **tetriminos);
void		display(char **tetriminos);
void		error(void);
int			ft_valid_form(char *str, int i, int first);
int			ft_check_size(char *str, int i, int j);
int			ft_nb_tetriminos(char *str);
int			ft_enough_char(char *str);
int			ft_check_char(char *str);

#endif
