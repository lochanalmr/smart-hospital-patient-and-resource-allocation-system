#include <stdio.h>
#include <string.h>
#include "patient_registration.h"
#include "calculations.h"
#include "data_arrays.h"

int patientRegistration(char name[], int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID,
                        int *daysAdmitted, int countPerSpecialty[], int patientCount, int specialtyIDs[], int wardIDs[],
                        int *waitTime, float *surcharge, int countPerWardID[], int *wardStayCost, float *totalBillValue,
                        float *ageSubsidyDiscount, float *finalAmountPayable, int *patientNoArray, int *bedNumber){
    printf("\n---Patient Registration---\n");

    printf("1 - Patient Details Collection\n");
    do {
        printf("Enter patient name: ");
        scanf(" %49[^\n]", name);
    } while (strlen(name) == 0);
    do{
        printf("Enter patient age: ");
        scanf("%d", age);
    }while(*age <= 0);
    do{
        printf("Emergency triage level (1 = Normal, 2 = Urgent, 3 = Critical): ");
        scanf("%d", triageLevel);
    }while(*triageLevel <= 0 || *triageLevel >= 4);

    printf("\n2 - Specialty selection\n");
    do{
        printf("Specialty ID (1 - 4): ");
        scanf("%d", specialtyID);
    }while(*specialtyID <= 0 || *specialtyID > 4);
    if (countPerSpecialty[*specialtyID - 1] == dailyPatientCaps[*specialtyID - 1]){
        printf("Selected specialty reached maximum capacity. Unable to register patient!\n");
        return 1;
    }
    else{
        countPerSpecialty[*specialtyID - 1] += 1;
    }

    printf("\n3 - Ward Admission Details\n");
    do{
        printf("Is admitted to ward? (1 = Yes, 0 = No): ");
        scanf("%d", admitted);
    }while(*admitted != 0 && *admitted != 1);

    if (*admitted == 1){
        do{
            printf("Enter ward ID (1 to 4): ");
            scanf("%d", wardID);
        }while(*wardID <= 0 || *wardID >= 5);
        if (countPerWardID[*wardID - 1] == totalBedCapacities[*wardID - 1]){
            printf("Selected ward reached maximum capacity. Unable to register patient!\n");
            countPerSpecialty[*specialtyID - 1] -= 1;
            return 1;
        }
        else{
            int bedIndex = findFreeBed(*wardID, bedOccupancy, totalBedCapacities);
            bedOccupancy[*wardID - 1][bedIndex] = patientCount + 1;
            *bedNumber = bedIndex + 1;
            countPerWardID[*wardID - 1] += 1;
            do{
                printf("Enter days admitted: ");
                scanf("%d", daysAdmitted);
            }while (*daysAdmitted <= 0);
        }
    }
    else if(*admitted == 0){
        *daysAdmitted = 0;
        *wardID = 0;
    }
    *waitTime = calculateEstimatedWaitingTime(patientCount, specialtyIDs, wardIDs, countPerSpecialty);
    *surcharge = calculateEmergencySurcharge(*triageLevel, *specialtyID);
    *wardStayCost = calculateWardStayCost(*wardID, *daysAdmitted);
    *totalBillValue = calculateTotalBill(baseConsultationFees[*specialtyID - 1], *surcharge, *wardStayCost);
    *ageSubsidyDiscount = calculateAgeSubsidyDiscount(*age, *totalBillValue);
    *finalAmountPayable = *totalBillValue - *ageSubsidyDiscount;
    *patientNoArray = patientCount;
    return 0;
}
