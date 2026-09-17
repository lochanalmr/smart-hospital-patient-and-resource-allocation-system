#include <stdio.h>
#include "sorting.h"
#include "billing.h"
#include "data_arrays.h"

void sortPatientsByPriority(int patientCount, int triageLevels[], int order[]){
    for (int i = 0; i < patientCount; i++){
        order[i] = i;
    }

    for (int i = 0; i < patientCount - 1; i++){
        int bestPosition = i;

        for (int j = i + 1; j < patientCount; j++){
            int candidate = order[j];
            int currentBest = order[bestPosition];

            if (triageLevels[candidate] > triageLevels[currentBest]){
                bestPosition = j;
            }
            else if (triageLevels[candidate] == triageLevels[currentBest] && candidate < currentBest){
                bestPosition = j;
            }
        }

        if (bestPosition != i){
            int temp = order[i];
            order[i] = order[bestPosition];
            order[bestPosition] = temp;
        }
    }
}

void displayPatientsByPriority(int patientCount, int order[], int patientNoArray[], char names[][NAME_SIZE],
                        int ages[], int triageLevels[], int specialtyIDs[], int admittedStatus[],
                        int wardIDs[], int bedNumbers[], int waitTimesArray[]){

    printf("------Displaying sorted list of patients-------\n");

    if (patientCount == 0){
        printf("No registered patients.\n");
        return;
    }

    printf("%-11s %-8s %-15s %-5s %-20s %-23s %-8s %-10s\n", "Priority", "Patient ID", "Name", "Age", "Urgency", "Specialty", "Ward", "Waiting Time (min)");

    for (int rank = 0; rank < patientCount; rank++){
        int p = order[rank];

        if (admittedStatus[p] == 1){
            printf("%-4d        PAT-%04d   %-15s %-5d %-20s %-20s  W%d-B%02d   %-10d\n", rank + 1, patientNoArray[p] + 1, names[p], ages[p],
                   triageLevelText(triageLevels[p]), specialtyNames[specialtyIDs[p] - 1],
                   wardIDs[p], bedNumbers[p], waitTimesArray[p]);
        }
        else{
            printf("%-4d        PAT-%04d   %-15s %-5d %-20s %-12s  %-8s %-10d\n", rank + 1, patientNoArray[p] + 1, names[p], ages[p],
                triageLevelText(triageLevels[p]), specialtyNames[specialtyIDs[p] - 1], "-", waitTimesArray[p]);
        }
    }
}
