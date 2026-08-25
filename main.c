#include <stdio.h>
#include <stdlib.h>
#include "data_arrays.h"
#include "patient_registration.h"

#define SIZE 50
#define CAPACITY 1000

int main(){
    printf("Smart Hospital Patient and Resource Allocation System\n");

    char names[CAPACITY][SIZE];
    int ages[CAPACITY] = {0};
    int triageLevels[CAPACITY] = {0};
    int specialtyIDs[CAPACITY] = {0};
    int admittedStatus[CAPACITY] = {0};
    int wardIDs[CAPACITY] = {0};
    int daysAdmitted[CAPACITY] = {0};
    int countPerSpecialty[4] = {0};
    int waitTimesArray[CAPACITY] = {0};
    float surchargesArray[CAPACITY] = {0.0};
    int countPerWardID[CAPACITY] = {0};
    int wardStayCosts[CAPACITY] = {0};
    float totalBillValues[CAPACITY] = {0};

    int patientCount = 0;
    int choice = 0;

    do{
        printf("\nMain Menu: \n");
        printf("1. Register Patient\n");
        printf("2. View Bill of a Patient\n");
        printf("3: Exit Program\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        int registrationStatus = 0;

        if (choice == 1 && patientCount <= CAPACITY){
            registrationStatus = patient_registration(
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
                wardIDs,
                &waitTimesArray[patientCount],
                &surchargesArray[patientCount],
                countPerWardID,
                &wardStayCosts[patientCount],
                &totalBillValues[patientCount]
            );
            if (registrationStatus == 0){
                printf("Patient %d successfully registered!\n", patientCount);
                patientCount++;
            }
        }

        else if(choice == 2){
            printf("View Bill of a Patient\n");
        }

        else if(choice == 3){
            printf("\nThank you for using Smart Hospital Patient and Resource Allocation System!\n");
            return 0;
        }
    } while (choice != 0);

    return 0;
}