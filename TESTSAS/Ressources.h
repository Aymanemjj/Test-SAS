#ifndef Ressources_h
#define Ressources_h
//FUNCTIONS
//Main Menu
int MainMenu();
//ProductListing
void ProductListing(int choicePC, int choicePS, int i);
//Profile Consultaion
void ProfileConsultation(int choicePM);
//Fund Deposit
void FundDeposit(float deposit);
//Product Selection
int ProductSelection(int choicePS, int i);
//Product search 
void ProductSearch(void);
//Product sort
void ProductSorting(void);
//Profile MOdification
void ProfileModification(void);
//ProfileCreation
struct Client ProfileCreation();
//emailgen
void emailgen(void);
//History updating
int HistoryUpdating(int choicePS, int Quantity);

extern int HistoryOrder;
//Buying
int Buying(int choicePS);




//STRUCTURES
//Client
struct Client
{
    int idClient;
    char nom[10];
    char prenom[10];
    char email[50];
    float solde;
};
extern struct Client C1;

//Produit
struct  Produit
{
    int idProduit;
    char nom[30];
    char categorie[20];
    float prix;
    int stock;
    char description[100];
};

//ProductList
extern struct Produit ProduitList[5];

//Histoy
struct History
{
    int Id;
    char name[30];
    float prix;
    int quantity;
    float total;
};
extern struct History history[10];
//stats printing
void StatsPrinting(struct History history[], int HistoryOrder);






#endif