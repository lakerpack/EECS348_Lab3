#include <stdio.h>

int main(){
    int choice;
    while (choice > 1){
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the NFL score: ");
        scanf("%d", &choice);
    }
    return 0;
}