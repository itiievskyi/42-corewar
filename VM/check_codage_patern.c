/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_codage_patern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:08:24 by averemiy          #+#    #+#             */
/*   Updated: 2018/08/03 19:08:57 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				c_c_ld_lld(int codage)
{
	int			arg1;
	int			arg2;

	arg1 = bit_mask(1, codage);
	arg2 = bit_mask(2, codage);
	if (arg1 != 2 && arg1 != 3)
		return (1);
	if (arg2 != 1)
		return (1);
	return (0);
}

int				c_c_sti(int codage)
{
	int			arg1;
	int			arg2;
	int			arg3;

	arg1 = bit_mask(1, codage);
	arg2 = bit_mask(2, codage);
	arg3 = bit_mask(3, codage);
	if (arg1 != 1)
		return (1);
	if (arg2 == 0)
		return (1);
	if (arg3 != 1 && arg3 != 3)
		return (1);
	return (0);
}

int				c_c_add_sub(int codage)
{
	int			arg1;
	int			arg2;
	int			arg3;

	arg1 = bit_mask(1, codage);
	arg2 = bit_mask(2, codage);
	arg3 = bit_mask(3, codage);
	if (arg1 != 1 && arg2 != 1 && arg3 != 1)
		return (1);
	return (0);
}

int				c_c_and_or_xor(int codage)
{
	int			arg1;
	int			arg2;
	int			arg3;

	arg1 = bit_mask(1, codage);
	arg2 = bit_mask(2, codage);
	arg3 = bit_mask(3, codage);
	if (arg1 == 0)
		return (1);
	if (arg2 == 0)
		return (1);
	if (arg3 != 1)
		return (1);
	return (0);
}

int				c_c_ldi_lldi(int codage)
{
	int			arg1;
	int			arg2;
	int			arg3;

	arg1 = bit_mask(1, codage);
	arg2 = bit_mask(2, codage);
	arg3 = bit_mask(3, codage);
	if (arg1 == 0)
		return (1);
	if (arg2 != 1 && arg2 != 3)
		return (1);
	if (arg3 != 1)
		return (1);
	return (0);
}
