#include <stdio.h>
#include "patient_registration.h"
#include "billing.h"
#include "data_arrays.h"

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
    float ageSubsidyDiscounts[CAPACITY] = {0};
    float finalPayableAmounts[CAPACITY] = {0};
    int patientNoArray[CAPACITY] = {0};
    int bedNumbers[CAPACITY] = {0};

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
            registrationStatus = patientRegistration(
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
                &totalBillValues[patientCount],
                &ageSubsidyDiscounts[patientCount],
                &finalPayableAmounts[patientCount],
                &patientNoArray[patientCount],
                &bedNumbers[patientCount]
            );
            if (registrationStatus == 0){
                printf("Patient %d successfully registered!\n", patientCount + 1);
                patientCount++;
            }
        }

        else if(choice == 2){
            if (patientCount == 0){
                printf("No registered patients.\n");
            }
            else{
                int selected = 0;
                printf("Enter Patient ID to display bill: ");
                scanf("%d", &selected);

                if (selected < 1 || selected > patientCount){
                    printf("Invalid patient ID.\n");
                }
                else{
                    int index = selected - 1;
                    displayPatientBill(
                        selected,
                        names[selected - 1],
                        ages[selected - 1],
                        triageLevels[selected - 1],
                        specialtyIDs[selected - 1],
                        admittedStatus[selected - 1],
                        wardIDs[selected - 1],
                        bedNumbers[selected - 1],
                        daysAdmitted[selected - 1],
                        baseConsultationFees[specialtyIDs[selected - 1] - 1],
                        surchargesArray[selected - 1],
                        wardStayCosts[selected - 1],
                        totalBillValues[selected - 1],
                        ageSubsidyDiscounts[selected - 1],
                        finalPayableAmounts[selected - 1],
                        waitTimesArray[selected - 1]
                    );
                }
            }
        }

        else if(choice == 3){
            printf("\nThank you for using Smart Hospital Patient and Resource Allocation System!\n");
            return 0;
        }
    } while (choice != 0);

    return 0;
}
