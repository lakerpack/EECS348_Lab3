#include <stdio.h>
#include <math.h>

void monthly_sales(double* inputs, char* months[]){
    printf("Monthly sales report for 2022: \n");
    printf("Month     Sales\n");
    for (int i = 0; i < 12; i++){
        printf("%s: $%.2f\n", months[i], inputs[i]);
    }
}

double convert(char* line){
    double value = 0;
    int decimal = 1;
    int counter = 0;
    int spare = 0;
    for (int i = 0; *(line + i) != '\0'; i++){
        if (*(line + i) == '.'){
            spare = i - 1; 
        }
    }
    for (int i = 0; *(line + i) != '\0'; i++){
        if (*(line + i) != '.'){
            value += (*(line + i) - '0') * pow(10, spare);
            spare--;
        }
    }
    return value;

}

int main(){ 
    FILE *input;
    char num[100];
    double inputs[100];
    char *months[12] = {"Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int length = 0;
    int counter = 2;
    input = fopen("input.txt", "r");
    while(fgets(num, 9, input)){
        if (counter % 2 == 0){
            inputs[length] = convert(num);
            length++;
        }
        counter++;
    }
    monthly_sales(inputs, months);
    fclose(input);
    return 0;
}