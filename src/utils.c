/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 03:57:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/21 09:30:47 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print4(char const *s1, char const *s2, char const *s3, char const *s4)
{
	write(1, s1, ft_strlen(s1));
	write(1, s2, ft_strlen(s2));
	write(1, s3, ft_strlen(s3));
	write(1, s4, ft_strlen(s4));
}
