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
//Top Widget:
GtkWidget *window;
//Builder object
GtkBuilder *builder;
//List of widgets
GtkWidget *fixed;
GtkWidget *button;
GtkWidget *label;
//Add more widgets here...

//The main function
int main(int argc, char* argv[])
{     
    //initialize GTK
    gtk_init(&argc, &argv);

    //Create the builder object from the UI/XML file
    builder = gtk_builder_new_from_file("gtx-test.glade");
    //Create the top widget
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    //Handling the gtk_main_quit when the proram is closed
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
    //Connect the widget signals
    gtk_builder_connect_signals(builder, NULL);

    //Definit the above declared widget pointer
    fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
    button = GTK_WIDGET(gtk_builder_get_object(builder, "button"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));

    //Show the top level
    gtk_widget_show(window);

    //Start the GTK loop
    gtk_main();

    //exit the program
    return EXIT_SUCCESS;
}

//Handle the signal(s)
void on_button_clicked(GtkButton *b)
{
    gtk_label_set_text(GTK_LABEL(label), (const gchar*)"Hello World!");
}
//Add more signal handler here...

