#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "admin.h"
#include <gtk/gtk.h>
enum
{
	ENOM,
	EPRENOM,
	ECIN,
	EID,
	EDDN,
	ESEXE,
	EPOSTE,
	COLUMNS,
};

void ajouter_personne (char utilisateur[],personne p)
{
	FILE *f=NULL;
	f=fopen(utilisateur,"a+");
        fprintf(f,"%s %s %s %s %d %d %d %s %s\n",p.nom,p.prenom,p.numero_de_cin,p.identifiant,p.d.jour,p.d.mois,p.d.annee,p.sexe,p.poste);
        fclose(f);
}
///////////////////////////////


void afficher(GtkWidget *liste,char texte[])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char numero_cin[30];
char identifiant[30];
char date_naissance[30];
char sexe[30];
char poste[30];
store=NULL;
FILE *f;
date d;personne p;

store = gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("numero_cin", renderer, "text",ECIN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",EID, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("date_naissance", renderer, "text",EDDN, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text",ESEXE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("poste", renderer, "text",EPOSTE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen(texte,"r");

if(f==NULL)
{
return;
}
else
{
f=fopen("users.txt", "r");
while(fscanf(f," %s %s %s %s %d %d %d %s %s",nom,prenom,numero_cin,identifiant,&p.d.jour,&p.d.mois,&p.d.annee,sexe,poste)!=EOF)
{
 sprintf(date_naissance,"%d/%d/%d",p.d.jour,p.d.mois,p.d.annee);

gtk_list_store_append (store, &iter);
gtk_list_store_set (store,&iter,ENOM,nom,EPRENOM,prenom,ECIN,numero_cin,EID,identifiant,EDDN,date_naissance,ESEXE,sexe,EPOSTE,poste,-1);
}

fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int rechercher_personne(char utilisateur[],char identifiant[])
{
    FILE *f=NULL;
    char ch1[30],ch2[30],ch3[50],ch4[50],s[20],c[20] ;
    int j,m,a,trouve=0,id;
    f=fopen("users.txt","r");
    if(f != NULL)
    {
        while(fscanf(f," %s %s %s %s %d %d %d %s %s ",ch1,ch2,c,ch4,&j,&m,&a,s,ch3)!=EOF)
        if(strcmp(ch4,identifiant)==0)
        {
	   trouve=1;
        }
    }
    fclose(f);
    return trouve;
}
void modifier_personne(personne p1)
{
    FILE *f=NULL;
    FILE *f1=NULL;
    personne p;
  
    
    f=fopen("users.txt","r");
    f1=fopen("temp.txt","w");
   
        while(fscanf(f,"%s %s %s %s %d %d %d %s %s",p.nom,p.prenom,p.numero_de_cin,p.identifiant,&p.d.jour,&p.d.mois,&p.d.annee,p.sexe,p.poste)!=EOF)
        {
            if(strcmp(p1.identifiant,p.identifiant)!=0)
            {
            fprintf(f,"%s %s %s %s %d %d %d %s %s\n",p.nom,p.prenom,p.numero_de_cin,p.identifiant,p.d.jour,p.d.mois,p.d.annee,p.sexe,p.poste);
            }
            else
            {
            
            fprintf(f1,"%s %s %s %s %d %d %d %s %s\n",p1.nom,p1.prenom,p1.numero_de_cin,p1.identifiant,p1.d.jour,p1.d.mois,p1.d.annee,p1.sexe,p1.poste);
            }
        }
    
    fclose(f);
    fclose(f1);
    remove("users.txt");
    rename("temp.txt","users.txt");
}
void supprimer_personne(char identifiant[50])
{
    FILE *f=NULL;
    FILE *fs=NULL;
    personne p;

    f=fopen("users.txt","r");
    fs=fopen("temp.txt","w");
        while(fscanf(f,"%s %s %s %s %d %d %d %s %s",p.nom,p.prenom,p.numero_de_cin,p.identifiant,&p.d.jour,&p.d.mois,&p.d.annee,p.sexe,p.poste)!=EOF)
        {
            if(strcmp(identifiant,p.identifiant)!=0)
            {
            fprintf(fs,"%s %s %s %s %d %d %d %s %s\n",p.nom,p.prenom,p.numero_de_cin,p.identifiant,p.d.jour,p.d.mois,p.d.annee,p.sexe,p.poste);
            }
    }
    fclose(f);
    fclose(fs);
    remove("users.txt");
    rename("temp.txt","users.txt");

}


