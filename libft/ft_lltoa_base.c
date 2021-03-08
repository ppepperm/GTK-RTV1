/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: out-belov1-mv <out-belov1-mv@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:13:19 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/03/06 13:57:35 by out-belov1-      ###   ########.fr       */
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
	// if (base < 2 && base > 16)
	// 	return (NULL);
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
