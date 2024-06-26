
#include "column.h"
//On a décide de faire un tableau de pointeurs qui pointes sur chaque colonne du CData
// Structure cdata

typedef struct {
    int nombre_elem; //taille logique
    COLUMN ** columns;
}CDATAFRAME;



//Fonction de gestion du CDataFrame
//1.Alimentation
CDATAFRAME * create_cdata(CDATAFRAME * cdata,int nbr);
CDATAFRAME * create_empty_cdata();
int fill_cdata(CDATAFRAME* cdata);
CDATAFRAME * auto_fill(CDATAFRAME * cdata);
//2.Affichage
void print_cdata (CDATAFRAME* cdata);
void print_cdata_lines(CDATAFRAME* cdata,int lim);
void print_cdata_col(CDATAFRAME* cdata, int lim);

//3.Opération usuelles
int add_line(CDATAFRAME* cdata);
int delete_line(CDATAFRAME* cdata,int ind);

// crée une nouvelle colonne dont le titre est "titre" et l'ajoute dans cdata
int add_col(CDATAFRAME* cdata, char * titre);

void delete_col(CDATAFRAME* cdata, int ind);
void rename_col(CDATAFRAME* cdata,int ind);
int val_exist(CDATAFRAME* cdata,int val);
int replace_val(CDATAFRAME* cdata,int pos_col,int pos_lig,int val);
void print_titles(CDATAFRAME* cdata);


//4.Analyse et statistiques
void print_nb_lines(CDATAFRAME* cdata);
void print_nb_col(CDATAFRAME* cdata);
int occ_val_cdata(CDATAFRAME* cdata,int val);
int sup_val_cdata(CDATAFRAME* cdata,int val); //supérieur
int inf_val_cdata(CDATAFRAME* cdata,int val);

//En plus
void print_menu();
void delete_cdata(CDATAFRAME* cdata);




