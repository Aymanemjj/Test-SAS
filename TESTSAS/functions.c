#include <stdio.h>
#include <string.h>
#include "Ressources.h"



//Menu Principal
int MainMenu(){
    int choiceMM;
    printf("=== SYSTÈME D'ACHAT CLIENT ===\n");
    printf("1. Gestion du profil client\n");
    printf("2. Gestion du solde virtuel\n");
    printf("3. Consultation des produits\n");
    printf("4. Effectuer un achat\n");
    printf("5. Mes statistiques\n");
    printf("0. Quitter l'application\n");
    printf("==============================\n");
    scanf("%d", &choiceMM);

    return choiceMM;
}



//Profile Creation
struct Client C1;
struct Client ProfileCreation(){
    printf("Input your name:\n");
    scanf("%s", C1.nom);
    printf("Input your last name:\n");
    scanf("%s", C1.prenom);
    C1.idClient = 101;
    C1.solde = 0;
    emailgen();    
    return C1;
}
//email gen
void emailgen(){
    strcpy(C1.email, C1.nom);
    strcat(C1.email, ".");
    strcat(C1.email, C1.prenom);
    strcat(C1.email, "@email.com");

}


//Profile Modification
void ProfileModification(){
    printf("Input the new name:\n");
    scanf("%s",C1.nom);
    printf("Input the new last name:\n");
    scanf("%s", C1.prenom);
    C1.idClient+=101;
    emailgen();

}
//Profile Consultation
void ProfileConsultation(int choicePM){
    printf("Profile ID: %d\nProfile full name: %s %s\nProfile email: %s\nFunds left: %.2fMAD\n\n\n\n", C1.idClient, C1.nom, C1.prenom, C1.email, C1.solde);
    printf("Input 1 to modify the info, and anything else to return to Main menu:\n");
    scanf("%d", &choicePM);
    if(choicePM==1){
        ProfileModification();
    }
}

//Funds deposit
void FundDeposit(float deposit){
    printf("Write how much you want to deposit:\n");
    scanf("%f", &deposit);
    C1.solde= C1.solde+deposit;
}


//Product List
struct Produit ProduitList[5] = {
    {1,"ordinateur portable","electronique",799,5,"Puissant et portable, idéal pour travail et divertissement."},
    {2,"smartphone","electronique",499,10,"Rapide et élégant, parfait pour appels, photos et apps."},
    {3,"casque audio","electronique",89,15,"Son clair et immersif pour musique et appels."},
    {4,"souris","electronique",25,20,"Précise et ergonomique pour travail et jeux."},
    {5,"clavier","electronique",45,12,"Compact et réactif, idéal pour bureautique et jeux."},
};

// History
struct History history[10];

//Product Listing

void ProductListing(int choicePC, int choicePS, int i){

    for(int i=0; i<5; i++){
        printf("%d-|%d.%s     Categorie:%s     Prix:%.2fMAD     Stock:%d\n", i, ProduitList[i].idProduit, ProduitList[i].nom, ProduitList[i].categorie, ProduitList[i].prix, ProduitList[i].stock);    
    };
    printf("\n\n");
    printf("Input 1 to search\nInput 2 to sort\nInput 3 to view details aobut a product:\n");
    scanf("%d",&choicePC);
    switch (choicePC) {
        case 1: 
            ProductSearch();
            break;
        case 2:
            ProductSorting();
            break;
        case 3:
            ProductSelection(choicePS, i);

    }
};

//Product search 
void ProductSearch(){
    char search[30];
    int x;
    printf("Input 1 to search by name, Input 2 to search by categorie:\nAnything else to return to Mainmenu\n");
    scanf("%d", &x);
    if(x==1){
            printf("Write the Product you want to find:\n");
            scanf("%s", search);
            for (int i=0;i<5;i++){
                if(strcmp(ProduitList[i].nom, search)==0){
                    printf("|%d.%s     Categorie:%s     Prix:%.2fMAD     Stock:%d\n", ProduitList[i].idProduit, ProduitList[i].nom, ProduitList[i].categorie, ProduitList[i].prix, ProduitList[i].stock);
                }
            }
        }else if(x==2){
            printf("Write the Categorie you want to find:\n");
            scanf("%s", search);
            for (int i=0;i<5;i++){
                if(strcmp(ProduitList[i].categorie, search)==0){
                    printf("|%d.%s     Categorie:%s     Prix:%.2fMAD     Stock:%d\n", ProduitList[i].idProduit, ProduitList[i].nom, ProduitList[i].categorie, ProduitList[i].prix, ProduitList[i].stock);
                }
            }
        }
}

//Product Sorting
void ProductSorting(){
    int choiceS;
    struct Produit x;
    printf("Do you want\n1-sorting acording to price\n2-sorting alphabetically\nOr you can type anything else to return to Mainmenu\n");
    scanf("%d",&choiceS);
    if(choiceS==1){
        printf("1-ascending\n2-descending\nAnything else to return to Mainmenu:\n");
        scanf("%d",&choiceS);
        if(choiceS==1){
            struct Produit ProduitListS[5];
            for(int i=0;i<5;i++){
                ProduitListS[i]=ProduitList[i];
            }

            for(int i=0;i<4;i++){
                for(int j=i+1;j<5;j++){
                    if(ProduitListS[i].prix>ProduitListS[j].prix){
                        x=ProduitListS[i];
                        ProduitListS[i]=ProduitListS[j];
                        ProduitListS[j]=x;
                        
                    }
                }
            }

            for(int i=0; i<5; i++){
            printf("%d-|%d.%s     Categorie:%s     Prix:%.2fMAD     Stock:%d\n", i+1, ProduitListS[i].idProduit, ProduitListS[i].nom, ProduitListS[i].categorie, ProduitListS[i].prix, ProduitListS[i].stock);    
            };
            printf("\n\n");

        }else if(choiceS==2){
            struct Produit ProduitListS[5];
            for(int i=0;i<5;i++){
                ProduitListS[i]=ProduitList[i];
            }

            for(int i=0;i<4;i++){
                for(int j=i+1;j<5;j++){
                    if(ProduitListS[i].prix<ProduitListS[j].prix){
                        x=ProduitListS[i];
                        ProduitListS[i]=ProduitListS[j];
                        ProduitListS[j]=x;
                        
                    }
                }
            }

            for(int i=0; i<5; i++){
            printf("%d-|%d.%s     Categorie:%s     Prix:%.2fMAD     Stock:%d\n", i+1, ProduitListS[i].idProduit, ProduitListS[i].nom, ProduitListS[i].categorie, ProduitListS[i].prix, ProduitListS[i].stock);    
            };
            printf("\n\n");

        }
    }
    else if(choiceS==2){
        struct Produit ProduitListA[5] = {
            {3,"Casque Audio","Electronique",89,15,"Son clair et immersif pour musique et appels."},
            {5,"Clavier","Electronique",45,12,"Compact et réactif, idéal pour bureautique et jeux."},
            {1,"Ordinateur Portable","Electronique",799,5,"Puissant et portable, idéal pour travail et divertissement."},
            {4,"Souris","Electronique",25,20,"Son clair et immersif pour musique et appels."},
            {2,"Smartphone","Electronique",499,10,"Rapide et élégant, parfait pour appels, photos et apps."},
          
        };
        for(int i=0;i<5;i++){
            printf("|%d.%s     Categorie:%s     Prix:%.2fMAD     Stock:%d\n", i+1, ProduitListA[i].nom, ProduitListA[i].categorie, ProduitListA[i].prix, ProduitListA[i].stock);  
        }
        printf("\n\n\n");
    }
}



//Buying
int Buying(int choicePS){
    int Quantity, i;
    printf("Type the quantity you want to buy:\n");
    scanf("%d",&Quantity);
    if(Quantity>ProduitList[choicePS-1].stock){
        printf("We only have %d left\n", ProduitList[choicePS-1].stock);
    }else if (Quantity<1){
        printf("ERROR\n");
        printf("Type anything to return to Main menu");
        scanf("%d",&i);
        
    }else {
            if(Quantity*ProduitList[choicePS-1].prix <= C1.solde){  
            
                C1.solde = C1.solde-(Quantity*ProduitList[choicePS-1].prix);
                ProduitList[choicePS-1].stock = ProduitList[choicePS-1].stock-Quantity;
                printf("Success!!, You bought %d of %s\n",Quantity, ProduitList[choicePS-1].nom);
                printf("You're total is %.2f MAD, you now have %.2f MAD left in your funds ", Quantity*ProduitList[choicePS-1].prix, C1.solde);
                printf("Type anything to return to Main menu\n");
                scanf("%d", &i);
                
            }else{
                printf("You have insufficiant funds, Pleas deposit more funds to buy this quantity\nYou're total %.2f MAD while you only have %.2f MAD", Quantity*ProduitList[choicePS-1].prix, C1.solde);
                printf("Type anything to return to Main menu\n");
                scanf("%d", &i);
            
            }
    }
    HistoryUpdating(choicePS, Quantity);
    return Quantity;
}



//ProductSelection
int ProductSelection(int choicePS, int i){
    printf("\n\n0 to return to Main menu\n");
    printf("Type the ID of the product to Show details:\n");
    scanf("%d",&choicePS);
    if (choicePS<0 || choicePS>5){
    printf("Error, none existing value\n");
    }else if (choicePS<=5 && choicePS!=0){
        printf("\n\n%d.%s\nCategorie: %s\nPrice: %.2fMAD\ninStock: %d\nDescription: %s\n\n\n", ProduitList[choicePS-1].idProduit, ProduitList[choicePS-1].nom, ProduitList[choicePS-1].categorie, ProduitList[choicePS-1].prix, ProduitList[choicePS-1].stock, ProduitList[choicePS-1].description);
        printf("Type 1 to buy, anything else to return to the main menu:\n");
        scanf("%d",&i);
        if (i==1){
            Buying(choicePS);
        }
    }

    return choicePS;
}


//Stats
int HistoryUpdating(int choicePS, int Quantity) {
    
    history[HistoryOrder].Id=ProduitList[choicePS-1].idProduit;
    strcpy(history[HistoryOrder].name,ProduitList[choicePS-1].nom);
    history[HistoryOrder].prix=ProduitList[choicePS-1].prix;
    history[HistoryOrder].quantity=Quantity;
    history[HistoryOrder].total=Quantity * ProduitList[choicePS-1].prix;
    HistoryOrder ++;
    return HistoryOrder;
}

//show stats and history

void StatsPrinting(struct History history[10], int HistoryOrder){
    for(int i =0;i<HistoryOrder;i++){
        printf("%d-|%d.%s     Prix:%.2f     Quantity:%d     Total:%.2f\n", i, history[i].Id, history[i].name, history[i].prix, history[i].quantity, history[i].total);    
    }
    printf("\n\n\n");
}