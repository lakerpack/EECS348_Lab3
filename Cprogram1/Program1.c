#include <stdio.h>
#include <math.h>

void monthly_sales(double* inputs, char* months[]){
    printf("Monthly sales report for 2022: \n");
    printf("Month     Sales\n");
    for (int i = 0; i < 12; i++){
        printf("%s: $%.2f\n", months[i], inputs[i]);
    }
}

void sales_summary(double* inputs, char* months[]){
    printf("Sales summary: \n");
    double max = 0;
    double min = inputs[0];
    double average = 0;
    int high;
    int low = 0;
    for (int i = 0; i < 12; i++){
        average += inputs[i];
        if (inputs[i] > max){
            max = inputs[i];
            high = i;
        } 
        if (low > inputs[i]){
            min = inputs[i];
            low = i;
        } 
    }
    average /= 12;
    printf("Minimum sales: $%.2f (%s)\n", min, months[low]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[high]);
    printf("Average sales: $%.2f \n", average);

}

void six_month(double* inputs, char* months[]){
    printf("Six-Month Moving Average Report: \n");
    double average = 0;
    for (int i = 0; i <= 6; i++){
        for (int j = 0 + i; j < 6 + i; j++){
            average += inputs[j];
        }
        printf("%s - %s  $%.2f \n", months[i], months[i + 5], average / 6);  
        average = 0;
    }
}

void sales_report(double* inputs, char* months[]){
    printf("Sales Report (Highest to Lowest): \n");
    printf("  Month    Sales  \n");
    double sorted[12];
    for (int i = 0; i < 12; i++){
        int lowest = i;
        for (int j = 1 + i; j < 12; j++){
            if (inputs[j] < inputs[lowest]){
                lowest = j;
            }
        }
        swap(&inputs[i], &inputs[lowest]);
    }
}

void swap(double* val1, double* val2){
    double placeholder = *val1;
    *val1 = *val2;
    *val2 = placeholder;
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
    printf("\n");
    sales_summary(inputs, months);
    printf("\n");
    six_month(inputs, months);
    printf("\n");
    sales_report(inputs, months);
    fclose(input);
    return 0;
}