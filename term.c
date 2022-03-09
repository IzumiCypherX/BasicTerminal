#include <vte/vte.h>

static void
child_ready(VteTerminal *term, GPid pid, GError *error, gpointer user_data)
{
    if (!term) return;
    if (pid == -1) gtk_main_quit();
}

int
main(int argc, char *argv[])
{
    GtkWidget *window, *term;

    /* Initialise GTK, the window and the terminal */
    gtk_init(&argc, &argv);
    term = vte_terminal_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Basic Terminal");

    /* Start a new shell */
    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(term),
        VTE_PTY_DEFAULT,
        NULL,         /* working directory  */
        command,      /* command */
        NULL,         /* environment */
        0,            /* spawn flags */
        NULL, NULL,   /* child setup */
        NULL,         /* child pid */
        -1,           /* timeout */
        NULL,         /* cancellable */
        child_ready,  /* callback */
        NULL);        /* user_data */

    /* Connect some signals */
    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
    g_signal_connect(term, "child-exited", gtk_main_quit, NULL);

    /* Put widgets together and run the main loop */
    gtk_container_add(GTK_CONTAINER(window), term);
    gtk_widget_show_all(window);
    gtk_main();
}