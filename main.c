/*
Project : CDataframe par Alina Frederic et Abdel Derra.
Le fichier principale contient le menu permettant d'utiliser les fonctions du CdataFrame.
Il permet aussi de tester les fonctions sur les colonnes. Pour cela, mettre en commentaire les parties nécessaires.

*/
#include <stdio.h>
#include "cdataframe.h"


int main() {


    //Partie sur la colonne
    //Fonctions basiques
    //Début partie 1
/*
    COLUMN * mycol ;
    mycol = create_column("My column");
    printf("Le titre: %s, la taille physique : %d\n",mycol ->titre,mycol->taille_ph);

    int val = 5;

    if (insert_value(mycol, val)) {
        printf("Value added successfully to my column\n");
    }
    else
    {
        printf("Error adding value to my column\n");

    }
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    print_col(mycol);

    printf("Saisir une valeur dont on veut connaitre le nombre d'occurrence :\n");
    int y;
    scanf("%d",&y);
    int occ;
    occ=nbr_occ(mycol,y); //nbr d'occ de y
    printf("Nombre doccurences :%d\n",occ);

    printf("Saisir une position (indice) :\n");
    int z;
    int pos;
    scanf("%d",&z);
    pos=pos_x(mycol,z);

    if (pos!= NULL) {
        printf("La valeur a la position %d est : %d\n", z, pos);
    } else {
        printf("La position %d est en dehors des limites de la colonne.\n", z);
    }

    printf("Saisir une valeur pour connaitre le nombre de valeur superieur a celle-ci :\n");
    int a;
    scanf("%d",&a);
    int sup;
    sup=sup_x(mycol, a);
    printf("Le nombre de valeurs supérieurs a %d est de %d\n",a,sup);

    printf("Saisir une valeur pour connaitre le nombre de valeur inferieur à celle-ci:\n");
    int b;
    scanf("%d",&b);
    int inf;
    inf=inf_x(mycol,b);
    printf("Le nombre de valeurs inferieur a %d est de %d",b,inf);

    printf("\nSaisir une valeur pour connaitre combien de valeurs lui sont egales:\n");
    int c;
    scanf("%d",&c);
    int equal;
    equal=equal_x(mycol,c);
    printf("Le nombre de valeurs egales à %d est de %d\n",c,equal);

    //Fin partie 1 */

/*
    // Parties des fonctions avancées sur les colonnes ( à mettre en parenthése la partie 1 )
    //Début partie 2

    COLUMN_AVC *mycol;
    mycol = create_column_avc("My column");
    printf("%s %d\n", mycol->titre, mycol->taille_ph);


    insert_value(mycol, 5);
    insert_value(mycol, 52);
    insert_value(mycol, 15);
    insert_value(mycol, 44);
    printf("Voici le tableau non trie : \n");

    print_col(mycol);

    int sortdir;
    int valid_index;
    printf("Choisir comment vous voulez trier votre tableau. \n0: Ascendent \n1: Descendent :\n");
    scanf("%d",&sortdir);
    printf("Votre colonne est :\n0 : Non triee \n-1 : Partiellement triee \n1 : Trie \n");
    scanf("%d",&valid_index);
    mycol->valid_index = valid_index;
    sort(mycol,  sortdir);


    printf("Voici le tableau index :\n");
    for (int i = 0; i < mycol->taille_log; i++) {
        printf("[%d] %llu\n", i, mycol->index[i]);
    }

    printf("Voici le tableau trie si non trie a le origine : \n");
    print_col_by_index(mycol);

    int val;
    printf("Choisir la valeur a recherche dans le tableau :\n");
    scanf("%d",&val);

    if (search_value_in_column(mycol, val) == 1)
    {
        printf("La valeur existe dans le tableau !\n");
    }else{
        printf("La valeur ne existe pas dans le tableau !\n");
    }

    erase_index(mycol);
  */

    //Fin partie 2




    //MENU
    //Partie sur le CDataframe (mettre en commentaire partie 1 et 2 sur la colonne pour plus de confort d'utilisation)

    CDATAFRAME *cdata = NULL;
    int nbr_col = 0; // taille_logique
    int choice;

    do {
        print_menu();
        printf("Entrez votre choice : \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (cdata == NULL) {
                    int choice_alim;
                    do {
                        printf("Alimentation\n");
                        printf("1. Creation de un CDataframe vide\n2. Remplissage du CDataframe a partir de saisies utilisateurs\n3. Remplissage en dur du CDataframe\n0. Retour\n ");
                        printf("Entrez votre choix : ");
                        scanf("%d", &choice_alim);
                        switch (choice_alim) {
                            case 1:
                                if (cdata == NULL) {
                                    cdata = create_empty_cdata();
                                    printf("Le CdataFrame vide a ete cree.\n");
                                } else {
                                    printf("Le CdataFrame est deja initialise.\n");
                                }
                                break;

                            case 2:
                                printf("Saisir le nombre de colonne du cdata\n");
                                scanf("%d", &nbr_col);
                                cdata = create_cdata(cdata,nbr_col);
                                if (fill_cdata(cdata)) {
                                    printf("Le CdataFrame a ete remplis\n");
                                } else {
                                    printf("Le CdataFrame n'a pas ete remplis\n");
                                }
                                break;

                            case 3:
                                cdata = auto_fill(cdata);
                                printf("Le CdataFrame a ete remplis en dur\n");
                                if (cdata == NULL) {
                                    printf("Erreur lors de la création du CDATAFRAME.\n");
                                }
                                break;

                            case 0 :
                                break;

                        }
                    } while (choice_alim > 0 && choice_alim <= 3);
                } else {
                    printf("Le CdataFrame nest pas initialise.\n");
                }
                break;
            case 2:
                if (cdata != NULL) {
                    int choice_aff;
                    int n;
                    do {
                        printf("Affichage\n");
                        printf("1. Afficher tout le CDataframe\n2. Afficher une partie des lines du CDataframe selon une limite fournie par lutilisateur\n3. Afficher une partie des colonnes du CDataframe selon une limite fournie par lutilisateur\n0. Retour\n ");
                        printf("Entrez votre choix : ");
                        scanf("%d", &choice_aff);
                        switch (choice_aff) {
                            case 1:
                                print_cdata(cdata);
                                break;

                            case 2:
                                printf("Saisir le nombre de lignes de valeurs a print :\n");
                                scanf("%d",&n);
                                print_cdata_lines(cdata,n);
                                break;

                            case 3:
                                printf("Saisir le nombre de colonnes a print :\n");
                                scanf("%d",&n);
                                print_cdata_col(cdata,n);
                                break;

                            case 0 :
                                break;

                        }
                    } while (choice_aff < 0 || choice_aff > 3);
                } else {
                    printf("Le CdataFrame nest pas initialise.\n");
                }
                break;

            case 3:
                printf("Operations usuelles :\n");
                printf("1. Ajouter une ligne\n");
                printf("2. Supprimer une ligne\n");
                printf("3. Ajouter une colonne\n"); // En cours
                printf("4. Supprimer une colonne\n");
                printf("5. Renommer une colonne\n");
                printf("6. Verifier lexistence dune valeur\n");
                printf("7. Remplacer une valeur\n");
                printf("8. Afficher les titres des colonnes\n");
                printf("0. Retour\n");

                int choice_operations;
                printf("Entrez votre choix : ");
                scanf("%d", &choice_operations);

                switch (choice_operations) {
                    case 1:
                        if (cdata != NULL) {
                            add_line(cdata);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 2:
                        if (cdata != NULL) {
                            int index;
                            printf("Entrez lindice de la ligne a supprimer : ");
                            scanf("%d", &index);
                            delete_line(cdata, index);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 3:
                        if (cdata != NULL) {
                            char titre[100];
                            printf("Quel est le titre de la colonne :");
                            scanf("%s", titre);
                            int resultat_ajout = add_col(cdata,titre);
                            if (resultat_ajout)
                            {
                                printf("Colonne bien ajoute!\n");
                            }
                            else {
                                printf("Impossible a ajouter\n");
                            }; //à modifier
                            continue;
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 4:
                        if (cdata != NULL) {
                            int index;
                            printf("Entrez lindice de la colonne a supprimer : ");
                            scanf("%d", &index);
                            delete_col(cdata,index);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 5:
                        if (cdata != NULL) {
                            int index;
                            printf("Entrez lindice de la colonne a renommer : ");
                            scanf("%d", &index);
                            rename_col(cdata, index);
                            printf("Le tire a bien ete renomme : \n");

                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 6:
                        if (cdata != NULL) {
                            int val;
                            printf("Entrez la valeur a rechercher : ");
                            scanf("%d", &val);
                            if (val_exist(cdata,val)){
                                printf("Valeur existante\n");
                            }else {
                                printf("Valeur non existante\n");
                            }
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 7:
                        if (cdata != NULL) {
                            int pos_col, pos_lig, new_val;
                            printf("Entrez lindice de la colonne : \n");
                            scanf("%d", &pos_col);
                            printf("Entrez lindice de la line : \n");
                            scanf("%d", &pos_lig);
                            printf("Entrez la nouvelle valeur de la colonne indice %d et ligne indice %d : \n",pos_col,pos_lig);
                            scanf("%d", &new_val);
                            replace_val(cdata, pos_col, pos_lig, new_val);
                            printf("La valeur a ete remplasse\n");
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 8:
                        if (cdata != NULL) {
                            print_titles(cdata);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 0:
                        break;

                    default:
                        printf("Choix invalide. Veuillez entrer un nombre entre 0 et 8.\n");
                }
                break;

            case 4:
                printf("Analyse et statistiques :\n");
                printf("1. Afficher le nombre de lignes\n");
                printf("2. Afficher le nombre de colonnes\n");
                printf("3. Occurrence de une valeur\n");
                printf("4. Superieure a une valeur\n");
                printf("5. Inferieure a une valeur\n");
                printf("0. Retour\n");

                int choice_analyse;
                printf("Entrez votre choix : ");
                scanf("%d", &choice_analyse);

                switch (choice_analyse) {
                    case 1:
                        if (cdata != NULL) {
                            print_nb_lines(cdata);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 2:
                        if (cdata != NULL) {
                            print_nb_col(cdata);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 3:
                        if (cdata != NULL) {
                            int val,nb_occ;
                            printf("Entrez la valeur a rechercher : ");
                            scanf("%d", &val);
                            nb_occ = occ_val_cdata(cdata,val);
                            printf("le nombre doccurences de %d est %d\n",val,nb_occ);
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 4:
                        if (cdata != NULL) {
                            int val,nb_sup;
                            printf("Entrez la valeur seuil : ");
                            scanf("%d", &val);
                            nb_sup = sup_val_cdata(cdata,val);
                            printf("le nombre de valeur superieure a %d est %d\n",val,nb_sup); ;
                        } else {
                            printf("Le CdataFrame nest pas initialise.\n");
                        }
                        break;
                    case 5:
                        if (cdata != NULL) {
                            int val,nb_inf;
                            printf("Entrez la valeur seuil : ");
                            scanf("%d", &val);
                            nb_inf = inf_val_cdata(cdata,val);
                            printf("le nombre de valeur inferieure a %d est %d\n",val,nb_inf); ;
                        } else {
                            printf("Le CdataFrame nest pas initialisé.\n");
                        }
                        break;
                    case 0:
                        break;
                    default:
                        printf("Choix invalide. Veuillez entrer un nombre entre 0 et 5.\n");
                }
                break;
            case 0:
                // ici
                delete_cdata(cdata);
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 4.\n");


        }
    } while (choice != 0);



    return 0;


}













