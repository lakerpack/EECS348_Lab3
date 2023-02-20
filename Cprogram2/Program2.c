#include <stdio.h>

void printOutcomes(int score){
    
}

int main(){
    int choice;
    do {
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the NFL score: ");
        scanf("%d", &choice);
        if (choice > 1) printOutcomes(choice);
    } while (choice > 1);
    return 0;
}