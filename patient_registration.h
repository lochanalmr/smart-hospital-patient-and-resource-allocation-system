#ifndef PATIENT_REGISTRATION_H_INCLUDED
#define PATIENT_REGISTRATION_H_INCLUDED

int patientRegistration(char name[], int *age, int *triageLevel, int *specialtyID, int *admitted,
                        int *wardID, int *daysAdmitted, int countPerSpecialty[], int patientCount,
                        int specialtyIDs[], int wardIDs[], int *waitTime, float *surcharge, int countPerWardID[],
                        int *wardStayCost, float *totalBillValue, float *ageSubsidyDiscount,
                        float *finalAmountPayable, int *patientNoArray, int *bedNumber);

#endif // PATIENT_REGISTRATION_H_INCLUDED
