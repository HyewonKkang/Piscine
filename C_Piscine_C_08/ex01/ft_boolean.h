/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hykang <hykang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:03:37 by hykang            #+#    #+#             */
/*   Updated: 2021/09/28 11:03:38 by hykang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

#include <unistd.h>

typedef int	t_bool;

# define TRUE   1
# define FALSE  0
# define SUCCESS    0
# define EVEN(x)    (x % 2) == 0
# define EVEN_MSG   "I have an even number of arguments.\n"
# define ODD_MSG    "I have an odd number of arguments.\n"

#endif
