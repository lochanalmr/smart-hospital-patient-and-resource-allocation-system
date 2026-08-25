#ifndef PATIENT_REGISTRATION_H
#define PATIENT_REGISTRATION_H

int patient_registration(char name[], int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID, int *daysAdmitted, int countPerSpecialty[], int patientCount, int specialtyIDs[], int wardIDs[], int *waitTime, float *surcharge, int countPerWardID[], int *wardStayCost);

#endif