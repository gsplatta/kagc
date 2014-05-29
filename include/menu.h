/* 
 * kagc is differential geometrical graphing software. 
 * menu.h is responsible for the menu in the GUI.
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

#ifndef __MENU_H__
#define __MENU_H__ 

#include <gtk/gtk.h>

/* GtkMenuItems */
GtkWidget *file, *filemenu;
GtkWidget *edit, *editmenu;
GtkWidget *view, *viewmenu;
GtkWidget *help, *helpmenu;

/* File Menu */
GtkWidget *new_menu_item;
GtkWidget *open_menu_item;
GtkWidget *save_menu_item;
GtkWidget *save_as_menu_item;
GtkWidget *close_menu_item;

/* Edit Menu */
GtkWidget *cut_menu_item;
GtkWidget *copy_menu_item;
GtkWidget *paste_menu_item;
GtkWidget *delete_menu_item;

/* View Menu */

/* Help Menu */
GtkWidget *about_menu_item;

/* Signals */

#endif /* __MENU_H__ */