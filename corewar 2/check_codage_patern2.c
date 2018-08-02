/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_codage_patern2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:01:58 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/01 16:28:51 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			c_c_st(int codage)
{
	int		arg1;
	int		arg2;

	arg1 = bit_mask(1, codage);
	arg2 = bit_mask(2, codage);
	if (arg1 != 1)
		return (1);
	if (arg2 != 1 && arg2 != 2)
		return (1);
	return (0);
}

int			c_c_aff(int codage)
{
	int		arg1;

	arg1 = bit_mask(1, codage);
	if (arg1 != 1)
		return (1);
	return (0);
}
