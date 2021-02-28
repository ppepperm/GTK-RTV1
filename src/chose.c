/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:26:36 by ppepperm          #+#    #+#             */
/*   Updated: 2021/02/28 17:41:30 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_object		*return_chosen(t_scene scene, double x, double y)
{
	t_ray		ray;
	t_p2		roots;
	t_p2		new_roots;
	t_object	*current;

	ray = get_ray(scene.camera, x - W_W / 2, W_H / 2 - y);
	current = NULL;
	roots = init_p2(2000000, 2000000);
	while (scene.objects)
	{
		new_roots = scene.objects->intersect(ray, *(scene.objects));
		if (new_roots.x >= 0 && new_roots.y >= 0)
		{
			if (min(roots.x, roots.y) > min(new_roots.x, new_roots.y))
			{
				roots = new_roots;
				current = scene.objects;
			}
		}
		scene.objects = scene.objects->next;
	}
	if (y >= 600)
		return (NULL);
	return (current);
}
