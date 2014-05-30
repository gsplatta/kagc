/* 
 * kagc is differential geometrical graphing software. 
 * gui.h is responsible for the basic callbacks and macros which don't 
 * belong anywhere else.
 * 
 * Copyright (C) 2014 Geoffrey Platta
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 
#ifndef __GUI_H__
#define __GUI_H__

#include <gtk/gtk.h>

#define DEFAULT_WIDTH 500
#define DEFAULT_HEIGHT 700

/* Exit events */
static void destroy_event (GtkWidget *widget, gpointer data);
static gboolean delete_event (GtkWidget *widget, GdkEvent *event, gpointer data);

#endif /* __GUI_H__ */