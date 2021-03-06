/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:24:39 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/28 18:18:44 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_error(char *l)
{
	if (l)
		free(l);
	write(1, "invalid file\n", 13);
	exit(EXIT_FAILURE);
}

void		*return_sphere(char **nums)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere*)malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->pos = init_p3(ft_atoip(nums[0]), ft_atoip(nums[1]), ft_atoip(nums[2]));
	sphere->r = ft_atoip(nums[3]);
	return ((void*)sphere);
}

void		*return_plane(char **nums)
{
	t_plane *plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		return (NULL);
	plane->dir = init_p3(ft_atoip(nums[0]), ft_atoip(nums[1]), ft_atoip(nums[2]));
	plane->d = ft_atoip(nums[3]);
	return ((void*)plane);
}

void		*return_cone(char **nums)
{
	t_cone *cone;

	if (!(cone = (t_cone*)malloc(sizeof(t_cone))))
		return (NULL);
	cone->pos = init_p3(ft_atoip(nums[0]), ft_atoip(nums[1]), ft_atoip(nums[2]));
	cone->r = ft_atoip(nums[3]);
	cone->c = ft_atoip(nums[4]);
	return ((void*)cone);
}

void		*return_cylinder(char **nums)
{
	t_cylinder *cylinder;

	if (!(cylinder = (t_cylinder*)malloc(sizeof(t_cylinder))))
		return (NULL);
	cylinder->pos = init_p3(ft_atoip(nums[0]),\
	ft_atoip(nums[1]), ft_atoip(nums[2]));
	cylinder->r = ft_atoip(nums[3]);
	return ((void*)cylinder);
}

void		*return_hyperboloid(char **nums)
{
    t_hyperboloid *hyperboloid;

    if (!(hyperboloid = (t_hyperboloid *)malloc(sizeof(t_cone))))
        return (NULL);
    hyperboloid->r = ft_atoip(nums[4]);
    hyperboloid->c = ft_atoip(nums[5]);
    return ((void*) hyperboloid);

}