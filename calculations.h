#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED

int calculate_estimated_waiting_time(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]);
float calculate_emergency_surcharge(int triageLevel, int specialtyID);
int calculate_ward_stay_cost(int wardID, int daysAdmitted);
float calculate_total_bill(int baseConsultationFee, float surcharge, int wardStayCost);

#endif // CALCULATIONS_H_INCLUDED