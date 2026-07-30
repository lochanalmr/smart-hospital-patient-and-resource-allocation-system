#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void patient_registration(char name[], int size, int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID, int *daysAdmitted);

int main(){
    printf("Smart Hospital Patient and Resource Allocation System\n");

    char name[SIZE];
    int age = 0;
    int triageLevel = 0;
    int specialtyID = 0;
    int admitted = 0;
    int wardID = 0;
    int daysAdmitted =0;
    
    patient_registration(name, SIZE, &age, &triageLevel, &specialtyID, &admitted, &wardID, &daysAdmitted);

    return 0;
}