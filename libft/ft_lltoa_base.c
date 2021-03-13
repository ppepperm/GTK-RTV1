/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:21:46 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/03/13 18:23:24 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_lltoa_base(long long num, int base)
{
	unsigned long long	tmp;
	unsigned long long	helplen;
	int					len;
	char				*ret;
	int					neg;

	len = 1;
	neg = num < 0 ? 1 : 0;
	if (!num)
		return (ft_strdup("0"));
	tmp = ft_absll(num);
	helplen = tmp;
	while ((helplen = helplen / base))
		len++;
	ret = (char*)ft_memalloc(len + neg + 1);
	ret[0] = num < 0 ? '-' : 0;
	while (tmp)
	{
		num = tmp % base;
		ret[--len + neg] = (num > 9) ? (num - 10) + 'a' : num + '0';
		tmp = tmp / base;
	}
	return (ret);
}
