/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:25:48 by ppepperm          #+#    #+#             */
/*   Updated: 2020/06/13 19:25:59 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void do_drawing(cairo_t *);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
							  gpointer user_data)
{
	do_drawing(cr);

	return FALSE;
}

/* actual drawing function*/
static void do_drawing(cairo_t *cr)
{
	/* set source colour black*/
	double x,y;
	x = 0;
	y = 0;
	while (x <= 800)
	{
		while (y <= 800)
		{
			cairo_set_source_rgb(cr, x/2,y/2,0);
			put_pixel(cr, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/* darea drawing area gtk_widget AND cairo context*/
	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);
	/* adding darea to window container*/
	g_signal_connect(G_OBJECT(darea), "draw",
					 G_CALLBACK(on_draw_event), NULL);
	g_signal_connect(window, "destroy",
					 G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);
	gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
	gtk_window_set_title(GTK_WINDOW(window), "GTK window");

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
