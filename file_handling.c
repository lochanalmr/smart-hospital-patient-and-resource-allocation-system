#include <stdio.h>
#include "file_handling.h"

int loadBedOccupancy(int bedOccupancy[4][20], int countPerWardID[4]){
    FILE *file = fopen("beds_status.txt", "r");

    if (file == NULL)
        return 0;

    for (int ward = 0; ward < 4; ward++){
        countPerWardID[ward] = 0;
        for (int bed = 0; bed < 20; bed++){
            if (fscanf(file, "%d", &bedOccupancy[ward][bed]) != 1){
                fclose(file);
                return 1;
            }
            if (bedOccupancy[ward][bed] != 0)
                countPerWardID[ward] += 1;
        }
    }

    fclose(file);
    return 0;
}

int saveBedOccupancy(const int bedOccupancy[4][20]){
    FILE *file = fopen("beds_status.txt", "w");

    if (file == NULL)
        return 1;

    for (int ward = 0; ward < 4; ward++){
        for (int bed = 0; bed < 20; bed++)
            fprintf(file, "%d ", bedOccupancy[ward][bed]);
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

int addPatientRecord(int patientNo, const char name[], int age, float totalBillValue, float ageSubsidyDiscount, float finalAmountPayable){
    FILE *file = fopen("patient_records.txt", "a");

    if (file == NULL)
        return 1;

    fprintf(file, "Patient ID: PAT-%04d Name: %s Age: %d Total bill: LKR %.2f Discount: LKR %.2f Final amount: LKR %.2f\n", patientNo, name, age, totalBillValue, ageSubsidyDiscount, finalAmountPayable);
    fclose(file);

    return 0;
}
