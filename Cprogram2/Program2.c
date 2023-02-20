#include <stdio.h>

void printOutcomes(int score){
    for (int safety = 0; safety * 2 <= score; safety++){
        for (int goal = 0; goal * 3 <= score; goal++){
            for (int touchdown = 0; touchdown * 6 <= score; touchdown++){
                for (int touchdown_g = 0; touchdown_g * 7 <= score; touchdown_g++){
                    for (int touchdown_c = 0; touchdown_c * 8 <= score; touchdown_c++){
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", touchdown_c, touchdown_g, touchdown, goal, safety);
                    }
                }
            }
        }
    }
}

int main(){
    int choice;
    do {
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the NFL score: ");
        scanf("%d", &choice);
        printf("\n");
        if (choice > 1) printOutcomes(choice);
    } while (choice > 1);
    return 0;
}