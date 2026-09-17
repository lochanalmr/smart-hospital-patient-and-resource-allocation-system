#ifndef REPORTS_H_INCLUDED
#define REPORTS_H_INCLUDED

#define SIZE 50

void generatePerformanceReport(int patientCount, int triageLevels[], float totalBillValues[],
    float ageSubsidyDiscounts[], float finalPayableAmounts[], int countPerWardID[],
    char names[][SIZE], int patientNoArray[]);

#endif // REPORTS_H_INCLUDED
