#include <stdio.h>
#include <stdlib.h>
#include "data_arrays.h"
#include "patient_registration.h"

#define SIZE 50
#define CAPACITY 45

int main(){
    printf("Smart Hospital Patient and Resource Allocation System\n");

    char names[CAPACITY][SIZE];
    int ages[CAPACITY] = {0};
    int triageLevels[CAPACITY] = {0};
    int specialtyIDs[CAPACITY] = {0};
    int admittedStatus[CAPACITY] = {0};
    int wardIDs[CAPACITY] = {0};
    int daysAdmitted[CAPACITY] = {0};

    int patientCount = 0;
    int choice = 0;
    int countPerSpecialty[4] = {0};

    do{
        printf("\nMain Menu: \n");
        printf("1. Register Patient\n");
        printf("2. View Bill of a Patient\n");
        printf("3: Exit Program\n");
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
                &daysAdmitted[patientCount],
                countPerSpecialty,
                patientCount,
                specialtyIDs,
                wardIDs
            );
            patientCount++;
            printf("Patient successfully registered!\n");
        }
        else if(choice == 2){
            printf("View Bill of a Patient");
        }
        else if(choice == 3){
            return 0;
        }
    } while (choice != 0);

    return 0;
}