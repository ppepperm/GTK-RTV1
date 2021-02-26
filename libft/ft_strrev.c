/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:28:41 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:28:41 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	t;

	i = -1;
	j = ft_strlen(s);
	while (++i < --j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
	return (s);
}
