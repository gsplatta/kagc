##ifndef __MENU_H__
#define __MENU_H__ 

#include <gtk/gtk.h>

/* GtkMenuItems */
GtkWidget *file;
GtkWidget *edit;
GtkWidget *view;
GtkWidget *help;

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

#endif /* __MENU_H__ */