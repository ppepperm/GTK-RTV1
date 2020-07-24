/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:08:49 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/14 13:08:51 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_threads(t_p_data **data, pthread_t **threads, pthread_attr_t *attr)
{
	*data = (t_p_data*)malloc(sizeof(t_p_data) * ((int)W_W));
	*threads = (pthread_t*)malloc(sizeof(pthread_t) * ((int)W_W));
	pthread_attr_init(attr);
}

void	*thread_trace(void *input)
{
	t_p_data	*data;
	t_ray		ray;
	t_rgb		colour;
	int			row;

	data = (t_p_data*)input;
	row = 0;
	while (row < W_H)
	{
		ray = get_ray(data->scene.camera, data->coll - W_W / 2, W_H / 2 - row);
		colour = trace_ray(ray, data->scene);
		data->win_buff[data->coll * 4 + 0 + row * data->pitch] = colour.b;
		data->win_buff[data->coll * 4 + 1 + row * data->pitch] = colour.g;
		data->win_buff[data->coll * 4 + 2 + row * data->pitch] = colour.r;
		data->win_buff[data->coll * 4 + 3 + row * data->pitch] = colour.a;
		row++;
	}
	pthread_exit(0);
}
