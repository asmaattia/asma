#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"

int b1;
int b2;
void
on_connexion__clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *login, *password, *authentification;
char user[20];
char pass[20];
int trouve;

login = lookup_widget (objet_graphique, "identifiantaa");
password = lookup_widget (objet_graphique, "motdepasseaa");

strcpy(user, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(pass, gtk_entry_get_text(GTK_ENTRY(password)));

authentification=create_liste_des_utilisateurs();
gtk_widget_show (authentification);

}

void
on_Ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout;

ajout=create_Ajout();
gtk_widget_show (ajout);

}

void
on_Modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modification;

modification=create_Modification_();
gtk_widget_show (modification);
}


void
on_Supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)    
{
GtkWidget *suppression;

suppression=create_Suppression_();
gtk_widget_show (suppression);
}

/////////////////////////////////////////////////////////////////////

void
on_femme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
personne p;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p.sexe,"Femme");
}


void
on_homme1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
personne p;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p.sexe,"Homme");
}



void
on_homme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
personne p1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p1.sexe,"Homme");
}


void
on_femme2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
personne p1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(p1.sexe,"Femme");
}
///////////////////////////

void
on_Sauvegarder_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
personne p;
char comp[20];
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *cin;
GtkWidget *poste;
GtkWidget *authentification;
GtkWidget *input1;
GtkWidget *input2;
nom = lookup_widget(objet_graphique, "nomajouteraa");
prenom = lookup_widget(objet_graphique, "prenomajouteraa");
identifiant = lookup_widget(objet_graphique, "identifiantajouteraa");
cin = lookup_widget(objet_graphique, "cinajouteraa");
jour = lookup_widget(objet_graphique, "jourajouteraa");
mois = lookup_widget(objet_graphique, "moisajouteraa");
annee = lookup_widget(objet_graphique, "anneajouteraa");
input1= lookup_widget(objet_graphique, "homme1");
input2=lookup_widget(objet_graphique, "femme1");
poste= lookup_widget(objet_graphique, "combobox_poste2");
strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p.identifiant, gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(p.numero_de_cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));
p.d.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p.d.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
p.d.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input1)))
strcpy(p.sexe,"Homme");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input2)))
strcpy(p.sexe,"Femme");


ajouter_personne ( "users.txt", p);
authentification =create_liste_des_utilisateurs();
gtk_widget_show (authentification);
}


 
void
on_oui_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
personne p1;
char comp[20];
GtkWidget *authentification;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *identifiant;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *cin;
GtkWidget *combobox;
GtkWidget *input1,*input2;

nom = lookup_widget(objet_graphique, "nommodificationaa");
prenom = lookup_widget(objet_graphique, "prenommodificationaa");
identifiant = lookup_widget(objet_graphique, "identifiantmodificationaa");
cin = lookup_widget(objet_graphique, "cinmodificationaa");
jour = lookup_widget(objet_graphique, "jourmodificationaa");
mois = lookup_widget(objet_graphique, "moismodificationaa");
annee = lookup_widget(objet_graphique, "anneemodificationaa");
combobox=lookup_widget(objet_graphique, "combobox_modification");
input1= lookup_widget(objet_graphique, "homme2");
input2=lookup_widget(objet_graphique, "femme2");
p1.d.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
p1.d.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
p1.d.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
strcpy(p1.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p1.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p1.identifiant, gtk_entry_get_text(GTK_ENTRY(identifiant)));
strcpy(p1.numero_de_cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(p1.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input1)))
strcpy(p1.sexe,"Homme");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input2)))
strcpy(p1.sexe,"Femme");



modifier_personne(p1);

authentification=create_liste_des_utilisateurs();
gtk_widget_show (authentification);


}



void
on_non_clicked                         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *retour;

retour=create_liste_des_utilisateurs();
gtk_widget_show (retour);
}



void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview1;
	GtkWidget *liste_des_utilisateurs_;

	liste_des_utilisateurs_=lookup_widget(button,"liste_des_utilisateurs_");
	treeview1=lookup_widget(button,"treeview1");
	liste_des_utilisateurs_ = create_liste_des_utilisateurs();
	gtk_widget_show (liste_des_utilisateurs_);
	gtk_widget_hide(liste_des_utilisateurs_);
	afficher(treeview1,"users.txt");
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* cin;
gchar* identifiant;
gchar* date ;
gchar* sexe;
gchar* poste;
personne p;



GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{

gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&identifiant,4,&date,5,&sexe,6,&poste,-1);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.numero_de_cin,cin);
strcpy(p.identifiant,identifiant);
strcpy(p.d.jour,date);
strcpy(p.d.mois,date);
strcpy(p.d.annee,date);
strcpy(p.sexe,sexe);
strcpy(p.poste,poste);

afficher(treeview,"users.txt");
}
}


void
on_buttonconfirmer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char identifiant[50];
GtkWidget *entrysupp;
entrysupp=lookup_widget(button,"entrysupp");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(entrysupp)));
supprimer_personne(identifiant);
}

