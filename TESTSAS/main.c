#include <stdio.h>
#include <string.h>
#include "Ressources.h"

int choiceMM,choicePS,choicePM, choicePC, HistoryOrder=0, i;
float deposit;



int main(){





ProfileCreation();

do {
    choiceMM=MainMenu();

    switch (choiceMM){
        case 1:
            ProfileConsultation(choicePM);
            break;
        case 2:
            FundDeposit(deposit);
            break;
        case 3:
            ProductListing(choicePC, choicePS, i);
            break;
        case 4:
            ProductSelection(choicePS,i);
            break;
        case 5:
            StatsPrinting(history, HistoryOrder);
            break;
        case 0:
            break;

    }

}while(choiceMM<6 && choiceMM!=0);



    return 0;
}
