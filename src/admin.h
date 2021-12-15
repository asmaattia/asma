#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include <gtk/gtk.h>

struct date_de_naissance {
int jour;
int mois;
int annee;
};
typedef struct date_de_naissance date ;


struct per  {
char nom[30];
char prenom[30];
char identifiant[30];
date d;
char numero_de_cin[30] ; 
char sexe[30]; 
char poste[50];
};typedef struct per personne;

void ajouter_personne(char utilisateur[],personne p);
void afficher(GtkWidget *liste,char texte[]);
void modifier_personne(personne p1);
void supprimer_personne(char identifiant[50]);
int rechercher_personne(char utilisateur[],char identifiant[]);
#endif
