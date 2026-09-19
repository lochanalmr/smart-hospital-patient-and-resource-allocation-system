#ifndef FILE_HANDLING_H_INCLUDED
#define FILE_HANDLING_H_INCLUDED

int loadBedOccupancy(int bedOccupancy[4][20], int countPerWardID[4]);
int saveBedOccupancy(const int bedOccupancy[4][20]);
int addPatientRecord(int patientNo, const char name[], int age, float totalBillValue, float ageSubsidyDiscount, float finalAmountPayable);

#endif // FILE_HANDLING_H_INCLUDED
