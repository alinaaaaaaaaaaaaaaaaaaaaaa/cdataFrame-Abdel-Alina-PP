
typedef struct {
    char* titre;
    int * donnees;
    int taille_log;
    int taille_ph;

    unsigned long long *index;
    int valid_index;
    // index valid
    // 0 : no index
    // -1 : invalid index
    // 1 : valid index
    int sort_dir;
    // direction de tri Ascendant ou Déscendant
    // 0 : ASC
    // 1 : DESC

} COLUMN;

//Fonction prévu pour la gestion de la colonne
COLUMN * create_column(char * titre);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN *col);
void print_col(COLUMN* col);

//4.1.5
int nbr_occ(COLUMN* col,int x);
int pos_x(COLUMN* col,int x);
int sup_x(COLUMN* col, int x);
int inf_x(COLUMN* col, int x);
int equal_x(COLUMN * col,int x);

// Fonctions avancées
#define ASC 0
#define DESC 1

int partition (COLUMN* col,int gauche,int droite) ;
void quicksort (COLUMN* col,int gauche,int droite );
void sort(COLUMN* col, int sort_dir);
void print_col_by_index(COLUMN *col);
void erase_index(COLUMN *col);
int check_index(COLUMN *col);
void update_index(COLUMN *col);
int search_value_in_column(COLUMN *col, int val);


