#ifndef CALCULATIONS_H
#define CALCULATIONS_H

int calculate_estimated_waiting_time(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]);
float calculate_emergency_surcharge(int triageLevel, int specialtyID);
int calculate_ward_stay_cost(int wardID, int daysAdmitted);

#endif