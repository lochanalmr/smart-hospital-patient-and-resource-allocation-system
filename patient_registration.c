#include <stdio.h>
#include <string.h>
#include "patient_registration.h"
#include "calculations.h"

void patient_registration(char name[], int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID, int *daysAdmitted, int countPerSpecialty[], int patientCount, int specialtyIDs[], int wardIDs[], int *waitTime, float *surcharge){
    printf("\n---Patient Registration---\n");

    printf("1 - Patient Details Collection\n");
    printf("Enter patient name: ");
    scanf("%s", name);
    printf("Enter patient age: ");
    scanf("%d", age);
    printf("Emergency triage level (1 = Normal, 2 = Urgent, 3 = Critical): ");
    scanf("%d", triageLevel);

    printf("\n2 - Specialty selection\n");
    printf("Specialty ID (1 - 4): ");
    scanf("%d", specialtyID);

    printf("\n3 - Ward Admission Details\n");
    printf("Is admitted to ward? (1 = Yes, 0 = No): ");
    scanf("%d", admitted);
    if (*admitted == 1){
        printf("Enter ward ID (1 to 4): ");
        scanf("%d", wardID);
        printf("Enter days admitted: ");
        scanf("%d", daysAdmitted);
    }
    else if(*admitted == 0){
        *daysAdmitted = 0;
        *wardID = 0;
    }
    for (int i = 0; i < 4; i++){
        if (i == *specialtyID){
            countPerSpecialty[i] += 1;
        }
    }
    
    *waitTime = calculate_estimated_waiting_time(patientCount, specialtyIDs, wardIDs, countPerSpecialty);
    *surcharge = calculate_emergency_surcharge(*triageLevel, *specialtyID);
    printf("%d\n", *waitTime);
    printf("%.2f\n", *surcharge);
}