#include <stdio.h>
#include "reports.h"
#include "data_arrays.h"

void generatePerformanceReport(int patientCount, int triageLevels[], float totalBillValues[],
    float ageSubsidyDiscounts[], float finalPayableAmounts[], int countPerWardID[],
    char names[][SIZE], int patientNoArray[]){

    if (patientCount == 0){
        printf("No registered patients.\n");
        return;
    }

    int level1Count = 0, level2Count = 0, level3Count = 0;
    float totalRevenueEarned = 0.0;
    float totalDiscountsGranted = 0.0;
    int highestPayingIndex = 0;

    for (int i = 0; i < patientCount; i++){
        if (triageLevels[i] == 1)
            level1Count++;
        else if (triageLevels[i] == 2)
            level2Count++;
        else if (triageLevels[i] == 3)
            level3Count++;

        totalRevenueEarned += finalPayableAmounts[i];
        totalDiscountsGranted += ageSubsidyDiscounts[i];

        if (totalBillValues[i] > totalBillValues[highestPayingIndex]){
            highestPayingIndex = i;
        }
    }

    printf("\n1. Patients Registered by Urgency Level\n");
    printf("Total Patients Registered : %d\n", patientCount);
    printf("Level 1 (Normal)          : %d\n", level1Count);
    printf("Level 2 (Urgent)          : %d\n", level2Count);
    printf("Level 3 (Critical)        : %d\n", level3Count);

    printf("\n2. Revenue & Discounts\n");
    printf("Total Revenue Earned      : LKR %10.2f\n", totalRevenueEarned);
    printf("Total Discounts Granted   : LKR %10.2f\n", totalDiscountsGranted);

    printf("\n3. Bed Occupancy Percentage Per Ward\n");
    for (int i = 0; i < 4; i++){
        float occupancyPercent = ((float)countPerWardID[i] / (float)totalBedCapacities[i]) * 100.0;
        printf("%-26s: %6.2f%%  (%d/%d beds occupied)\n",
            wardNames[i], occupancyPercent, countPerWardID[i], totalBedCapacities[i]);
    }

    printf("\n4. Highest-Paying Patient\n");
    printf("Patient Name              : %s\n", names[highestPayingIndex]);
    printf("Patient ID                : PAT-%04d\n", patientNoArray[highestPayingIndex] + 1);
    printf("Total Bill                : LKR %10.2f\n", totalBillValues[highestPayingIndex]);
}
