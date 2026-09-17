#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#define NAME_SIZE 50

void sortPatientsByPriority(int patientCount, int triageLevels[], int order[]);
void displayPatientsByPriority(int patientCount, int order[], int patientNoArray[], char names[][NAME_SIZE],
                        int ages[], int triageLevels[], int specialtyIDs[], int admittedStatus[],
                        int wardIDs[], int bedNumbers[], int waitTimesArray[]);

#endif // SORTING_H_INCLUDED
