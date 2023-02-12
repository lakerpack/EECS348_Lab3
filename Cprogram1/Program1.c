#include <stdio.h>

int main(){ 
    FILE *input;
    char num[100];
    char *inputs[100];
    char months[][11] = {"Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int length = 0;
    int counter = 2;
    input = fopen("input.txt", "r");
    while(fgets(num, 9, input)){
        if (counter % 2 == 0){
            inputs[length] = num;
            printf("added: %s at %d\n", inputs[length], length);
            length++;
        }
        counter++;
    }
    fclose(input);
    return 0;
}