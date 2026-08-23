#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 50
#define CAPACITY 45

void patient_registration(char name[], int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID, int *daysAdmitted);

int main(){
    printf("Smart Hospital Patient and Resource Allocation System\n");

    // Arrays for storing patient registration data
    char names[CAPACITY][SIZE];
    int ages[CAPACITY] = {0};
    int triageLevels[CAPACITY] = {0};
    int specialtyIDs[CAPACITY] = {0};
    int admittedStatus[CAPACITY] = {0};
    int wardIDs[CAPACITY] = {0};
    int daysAdmitted[CAPACITY] = {0};

    int patientCount = 0;
    int choice = 0;

    do{
        printf("\nMain Menu: \n");
        printf("1. Register Patient\n");
        printf("2: Exit Program\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        if (choice == 1 && patientCount <= CAPACITY){
            patient_registration(
                names[patientCount], 
                &ages[patientCount], 
                &triageLevels[patientCount], 
                &specialtyIDs[patientCount], 
                &admittedStatus[patientCount], 
                &wardIDs[patientCount], 
                &daysAdmitted[patientCount]);
            patientCount++;
        }
        else if(choice == 2){
            return 0;
        }
    } while (choice != 0);

    return 0;
}