/* 
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
#include <gdk/gdkkeysyms.h>

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
GtkWidget *file_separator_menu_item;
GtkWidget *close_menu_item;

/* Edit Menu */
GtkWidget *cut_menu_item;
GtkWidget *copy_menu_item;
GtkWidget *paste_menu_item;
GtkWidget *undo_menu_item;
GtkWidget *redo_menu_item;
GtkWidget *edit_separator_menu_item;
GtkWidget *delete_menu_item;

/* View Menu */

/* Help Menu */
GtkWidget *documentation_menu_item;
GtkWidget *help_separator_menu_item;
GtkWidget *about_menu_item;

/* Hotkey group */
GtkAccelGroup *accelerators;

/* Signals, unimplemented as of yet */
static void new_menu_item_clicked (GtkWidget *widget);
static void open_menu_item_clicked (GtkWidget *widget);
static void save_menu_item_clicked (GtkWidget *widget);
static void save_as_menu_item_clicked (GtkWidget *widget);
static void close_menu_item_clicked (GtkWidget *widget);

static void undo_menu_item_clicked (GtkWidget *widget);
static void redo_menu_item_clicked (GtkWidget *widget);
static void cut_menu_item_clicked (GtkWidget *widget);
static void copy_menu_item_clicked (GtkWidget *widget);
static void paste_menu_item_clicked (GtkWidget *widget);
static void delete_menu_item_clicked (GtkWidget *widget);

static void about_menu_item_clicked (GtkWidget *widget);

#endif /* __MENU_H__ */