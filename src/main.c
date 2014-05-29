/* 
 *	main.c creates the GUI and, of course, runs the main program.
 *
 * 	The GUI consists of six basic parts:
 * 
 * 	1. The Window
 * 		The window is the container for everything.
 *  2. Grid
 *  	The grid is the container inside the window which holds the other parts.
 *  3. Menu
 *  	
 *  4. Worksheet
 *  	Most user interaction will occur within the worksheet. 
 *
 * 		The worksheet is essentially a text editor.
 * 		
 *  5. Scroll Window
 *
 *  6. Status Bar
 *  
 */ 

#include <gtk/gtk.h>
#include "worksheet.h"
#include "menu.h"
#include "statusbar.h"

int main(int argc, char const *argv[]) {
	/* 1. Initialize Gtk */
	gtk_init (&argc, &argv);

	/* 2. Create Widgets */
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *menu;
	GtkWidget *worksheet;
	GtkWidget *statusbar;
	GtkWidget *scroll_window;

	/* 3. Place the Widgets */

	/*   1. Create the window. */
	window 	= gtk_window_new (GTK_TOP_LEVEL);

	/* 	 2. Create the Grid. */
	grid 	= gtk_grid_new ();

	/*   3. Create the Menu Button. */
	menu 	= gtk_menu_button_new ();
	file	= gtk_menu_item_new_with_mnemonic ("_File");
	edit 	= gtk_menu_item_new_with_mnemonic ("_Edit");
	view	= gtk_menu_item_new_with_mnemonic ("_View");
	help	= gtk_menu_item_new_with_mnemonic ("_Help");

	/* 4. Implement event listening and callback functions for the widgets. */
	g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);
	g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy_event), NULL);

	/* 5. Show the widgets. */

	/* 6. Begin the event-handling loop. */
	gtk_show_all (window);

	gtk_main ();

	/* 7. Shut down the application. 
	 *		This was taken care of with the g_signal_connect calls with "delete_event" and "destroy_event,
	 *		but this is remaining here if cleanup is needed before exiting. */

	return 0;
};

static void
destroy_event (GtkWidget *widget, gpointer data) {
	gtk_main_quit ();
}

static gboolean
delete_event (GtkWidget *widget, GdkEvent *event, gpointer data) {
	return FALSE;
}