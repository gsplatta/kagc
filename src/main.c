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

#include <gtk/gtk.h>
#include "gui/gui.h"
#include "gui/worksheet.h"
#include "gui/menu.h"
#include "gui/statusbar.h"

int main(int argc, char *argv[]) 
{

	/* 1. Initialize Gtk */
	gtk_init(&argc, &argv);

	/* 2. Create Widgets */


	/* 3. Place the Widgets */

	/*   1. Create the window. */
	window 	= gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), DEFAULT_WIDTH, DEFAULT_HEIGHT);
	gtk_window_set_title(GTK_WINDOW(window), "KAGC");

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_container_add(GTK_CONTAINER(window), box);

	/* 	 2. Create the Menu. */
	initialize_menu();
	gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 0);

	/* 3. Create the Worksheet */
	initialize_worksheet();
	gtk_box_pack_end(GTK_BOX(box), scroll_window, TRUE, TRUE, 0);
	

	/* 4. Create the Status Bar. */



	/* 5. Implement event listening and callback functions for the widgets. */
	g_signal_connect(G_OBJECT (window), "delete_event", G_CALLBACK(delete_event), NULL);
	g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK(destroy_event), NULL);

	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(close_menu_item), "activate", G_CALLBACK(gtk_main_quit), NULL);

	/* 6. Show the widgets. */
	gtk_widget_show_all(window);

	/* 7. Begin the event-handling loop. */

	gtk_main();

	/* 8. Shut down the application. 
	 *		This was taken care of with the g_signal_connect calls with "delete_event" and "destroy_event,
	 *		but this is remaining here if cleanup is needed before exiting. */

	return 0;
}

static void initialize_menu() 
{
	menubar	 = gtk_menu_bar_new();
	filemenu = gtk_menu_new();
	editmenu = gtk_menu_new();
	viewmenu = gtk_menu_new();
	helpmenu = gtk_menu_new();

	file = gtk_menu_item_new_with_mnemonic("_File");
	edit = gtk_menu_item_new_with_mnemonic("_Edit");
	view = gtk_menu_item_new_with_mnemonic("_View");
	help = gtk_menu_item_new_with_mnemonic("_Help");

	new_menu_item = gtk_menu_item_new_with_label("New");
	open_menu_item = gtk_menu_item_new_with_label("Open");
	save_menu_item	= gtk_menu_item_new_with_label("Save");
	save_as_menu_item = gtk_menu_item_new_with_label("Save As");
	file_separator_menu_item = gtk_separator_menu_item_new();
	close_menu_item	= gtk_menu_item_new_with_label("Close");

	cut_menu_item = gtk_menu_item_new_with_label("Cut");
	copy_menu_item = gtk_menu_item_new_with_label("Copy");
	paste_menu_item	= gtk_menu_item_new_with_label("Paste");
	undo_menu_item = gtk_menu_item_new_with_label("Undo");
	redo_menu_item = gtk_menu_item_new_with_label("Redo");
	edit_separator_menu_item = gtk_separator_menu_item_new();
	delete_menu_item = gtk_menu_item_new_with_label("Delete");

	documentation_menu_item = gtk_menu_item_new_with_label("Documentation");
	help_separator_menu_item = gtk_separator_menu_item_new();
	about_menu_item	= gtk_menu_item_new_with_label("About");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM (file), filemenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), save_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), save_as_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), file_separator_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), close_menu_item);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), editmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), undo_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), redo_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), cut_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), copy_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), paste_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), edit_separator_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), delete_menu_item);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(view), viewmenu);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), documentation_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), help_separator_menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about_menu_item);

	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), edit);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), view);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

	accelerators = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accelerators);

	gtk_widget_add_accelerator(new_menu_item, "activate", accelerators, GDK_KEY_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(open_menu_item, "activate", accelerators, GDK_KEY_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(save_menu_item, "activate", accelerators, GDK_KEY_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(save_as_menu_item, "activate", accelerators, GDK_KEY_s, GDK_SHIFT_MASK | GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(close_menu_item, "activate", accelerators, GDK_KEY_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	gtk_widget_add_accelerator(undo_menu_item, "activate", accelerators, GDK_KEY_z, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(redo_menu_item, "activate", accelerators, GDK_KEY_y, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(cut_menu_item, "activate", accelerators, GDK_KEY_x, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(copy_menu_item, "activate", accelerators, GDK_KEY_c, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(paste_menu_item, "activate", accelerators, GDK_KEY_v, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(delete_menu_item, "activate", accelerators, GDK_KEY_Delete, 0, GTK_ACCEL_VISIBLE);

	gtk_widget_add_accelerator(documentation_menu_item, "activate", accelerators, GDK_KEY_F1, 0, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(about_menu_item, "activate", accelerators, GDK_KEY_a, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
}

static void initialize_worksheet() {
	scroll_window = gtk_scrolled_window_new(NULL, NULL);
	worksheet = gtk_text_view_new();
	gtk_container_add(GTK_CONTAINER(scroll_window), worksheet);
}

static void destroy_event(GtkWidget *widget, gpointer data) 
{
	gtk_main_quit();
}

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) 
{
	return FALSE;
}
