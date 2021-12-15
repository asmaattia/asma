#include <gtk/gtk.h>


void
on_connexion__clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_femme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_homme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Sauvegarder_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_oui_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_non_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_Supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonconfirmer_clicked             (GtkButton       *button,
                                        gpointer         user_data);
