#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N) 
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) ) 





// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)

// 3- apres chaque coordonnées il faut verifier les regles du sudoku sur le tableauJoueur donc : 

    // - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)
    // - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)

// 4 - Ecrire le code principal qui permet de jouer au joueur : le programme prend fin quand on gagne 




int verifierLigneColonne(int tab[8][8], int index, int LignOrCol){
    int result = 0;
    int counter = 10;
    int past = 2;
    int pastPast = 3;

    if(LignOrCol){ // ligne
        counter -= 10; 
        for(int i=0; i<8; i++){

            
            if (tab[index][i] != past && tab[index][i] != pastPast){ // test doublon
                pastPast = past;
                if (tab[index][i] == 1){ // test equilibre
                    counter += 1;
                    past = 1;
                }else{
                    counter -= 1;
                    past = 0;
                }
            }else {
                // result = 2;
                return result;
            }
            
        }
        if (counter != 0){ // renvoie mauvaise equilibre
            if (counter < 0){
                printf("une colonne contient trop de 0.");
            }else if (counter > 0){
                printf("une colonne contient trop de 1.");
            }
            return result;
        }
        result = 1;

    }else{ // colonne
        counter -= 10; 
        for(int i=0; i<8; i++){
            

            if (tab[i][index] != past && tab[i][index] != pastPast){ // test doublon
                pastPast = past;
                if (tab[i][index] == 1){ // test equilibre
                    counter += 1;
                    past = 1;
                }else{
                    counter -= 1;
                    past = 0;
                }
            }else {
                // result = 2;
                return result;
            }
            
            
        }
        if (counter != 0){ // renvoie mauvaise equilibre
            if (counter < 0){
                printf("une colonne contient trop de 0.");
            }else if (counter > 0){
                printf("une colonne contient trop de 1.");
            }
            return result;
        }
        result = 1;
    }
    return result;
}

// return 2 pour doublon / return 1 pour Juste / return 0 si non-equilibre





int verifierGrille(int tab[8][8]){
    int isCorrect = 1;
    for(int i = 0; i < 8; i++){
        int verifCol = verifLigneColonne(tab, 0);
        int verifLign = verifLigneColonne(tab, 1);
        if (verifCol || verifLign){
            printf("Il semble que vous ne respectez pas les règles (ᅌᴗᅌ* )");
            isCorrect = 0;
        }
    }
}




void copyArray(int tab[8][8], int tabTemp[8][8]){
    
    for(int i = 0;i < 8; i++){
        for(int j = 0;j < 8; j++){
            tabTemp[j][i] = tab[j][i];
        }
    }
}





int saisir(int tab[8][8]){
    int result = 0;
    
    while(result != 1){
        int saisie = 0;
        
        int tabTemp[8][8] = {
            {5,5,5,5, 5,5,5,5},
            {5,5,5,5, 5,5,5,5},
            {5,5,5,5, 5,5,5,5},
            {5,5,5,5, 5,5,5,5},
            
            {5,5,5,5, 5,5,5,5},
            {5,5,5,5, 5,5,5,5},
            {5,5,5,5, 5,5,5,5},
            {5,5,5,5, 5,5,5,5},
            
        };
        
        copyArray(tab, tabTemp);
        
        printf("Veuillez saisir un I");
        scanf("%d", &saisie);
        int saisieI = saisie;
        
        printf("Veuillez saisir un J");
        scanf("%d", &saisie);
        int saisieJ = saisie;
        
        if(tab[saisieI][saisieJ] == 5){
            printf("Cette case est deja remplie Reessayez\n");
        } else {
            printf("Quelle valeur souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie;
            tabTemp[saisieI][saisieJ] = saisieVal;
            result = verifierGrille(tabTemp);
            if(result){
                tab[saisieI][saisieJ] = saisieVal;
            }
        }
        
    }
    
    
}





int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  

    int solution[8][8] = {
        {1,1,0,1, 0,1,0,0},
        {0,0,1,0, 1,0,1,1},
        {0,1,0,0, 1,1,0,1},
        {1,0,1,1, 0,0,1,0},
    
        {1,0,1,0, 0,1,1,0},
        {0,1,0,1, 1,0,0,1},
        {1,1,0,0, 1,0,1,0},
        {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i) 
    {
    for(j=0; j<8; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 



    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

