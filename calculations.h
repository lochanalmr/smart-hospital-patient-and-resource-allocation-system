#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED

int calculate_estimated_waiting_time(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]);
float calculate_emergency_surcharge(int triageLevel, int specialtyID);

#endif // CALCULATIONS_H_INCLUDED