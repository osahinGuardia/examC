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

// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne 













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
        
        if(tab[saisieX][saisieY] == 5){
            printf("Cette case est deja remplie Reessayez\n");
        } else {
            printf("Quelle valeur souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie;
            tabTemp[saisieX][saisieY] = saisieVal;
            result = verifierGrille(tabeauTemporaire);
            if(result){
                tab[saisieX][saisieY] = saisieVal;
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

