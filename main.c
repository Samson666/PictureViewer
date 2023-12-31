//JJ 2023/12/25
//This document contains a skeleton/example in C to build a GTK Gui from a .UI/XML File
//The Makefile is also provided
//The program builds and run as is, but have to be customized to your needs
//The program does not have to be rebuild after the UI File has been changed.
//
//Change the makefile:  EXECUTABLE -> name of the resulting .bin file
//                      SRC -> name of this file
//call make clean
//call make run to build and start the program

//Needed include Files
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk.h>
#include <gtkx.h>
#include <math.h>
#include <ctype.h>

//Pointer declarations
//Builder object
GtkBuilder *builder;
//List of widgets
//Main Window
GtkWidget *window;
GtkWidget *window_box;
GtkWidget *window_image;
GtkWidget *window_button_box;
GtkWidget *window_button_open;
GtkWidget *window_button_close;

static void open_file_dialog()
{
    GtkWidget *file_dialog;
    file_dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(window),
                                              GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK, GTK_RESPONSE_OK,
                                              GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
    gtk_widget_show(file_dialog);
    gint resp = gtk_dialog_run(GTK_DIALOG(file_dialog));
    if(resp == GTK_RESPONSE_OK) printf("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_dialog)));
    else printf("You pressed Cancel!\n");
    gtk_widget_destroy(file_dialog);                                          
}

//The main function
int main(int argc, char* argv[])
{     
    //initialize GTK
    gtk_init(&argc, &argv);

    //Create the builder object from the UI/XML file
    builder = gtk_builder_new_from_file("PictureViewer.glade");
    //Create the top widget
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    //Handling the gtk_main_quit when the program is closed
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
    //Connect the widget signals
    gtk_builder_connect_signals(builder, NULL);

    //Define the above declared widget pointer
    //Main window
    window_box = GTK_WIDGET(gtk_builder_get_object(builder, "window_box"));
    window_image = GTK_WIDGET(gtk_builder_get_object(builder, "window_image"));
    window_button_box = GTK_WIDGET(gtk_builder_get_object(builder, "window_button_box"));
    window_button_open = GTK_WIDGET(gtk_builder_get_object(builder, "window_button_open"));
    window_button_close = GTK_WIDGET(gtk_builder_get_object(builder, "window_button_close"));

    g_signal_connect(window_button_close,"clicked", G_CALLBACK(gtk_main_quit),NULL);

    //Show the top level
    gtk_widget_show(window);

    //Start the GTK loop
    gtk_main();

    //exit the program
    return EXIT_SUCCESS;
}

// //Handle the signal(s)


void on_window_button_open_clicked()
{
    open_file_dialog();
}

void on_window_button_close_clicked()
{
    gtk_button_set_label(GTK_BUTTON(window_button_close), (const gchar*)"Close");
}
