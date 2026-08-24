#ifndef PATIENT_REGISTRATION_H_INCLUDED
#define PATIENT_REGISTRATION_H_INCLUDED

void patient_registration(char name[], int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID, int *daysAdmitted, int countPerSpecialty[], int patientCount, int specialtyIDs[], int wardIDs[], int *waitTime, float *surcharge);

#endif // PATIENT_REGISTRATION_H_INCLUDED