/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:37:43 by hykang            #+#    #+#             */
/*   Updated: 2021/09/19 23:08:34 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_error(void);
int		count_digit(char *str);
int		param_is_valid(char *str, int max_value);
int		**create_table(char *params, int max_value);
void	print_table(int **arr, int max_value);
int		resolve(int **arr, int max_value, int x, int y);
int		check_col_up(int **arr, int x, int max_value);
int		check_col_down(int **arr, int x, int max_value);
int		check_row_left(int **arr, int y, int max_value);
int		check_row_right(int **arr, int y, int max_value);
int		check_four_directions(int **arr, int max_value);

#endif
