#ifndef _WORKSHEET_H_
#define _WORKSHEET_H_

#include <gtk/gtk.h>

static void destroy_event (GtkWidget *widget, gpointer data);
static gboolean delete_event (GtkWidget *widget, GdkEvent *event, gpointer data);

#endif /* _WORKSHEET_H_ */