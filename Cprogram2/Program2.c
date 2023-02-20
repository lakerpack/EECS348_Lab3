#include <stdio.h>

int main(){
    int choice;
    do {
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the NFL score: ");
        scanf("%d", &choice);
    } while (choice > 1);
    return 0;
}