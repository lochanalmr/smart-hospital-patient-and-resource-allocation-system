#ifndef CALCULATIONS_H
#define CALCULATIONS_H

int calculate_estimated_waiting_time(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]);
float calculate_emergency_surcharge(int triageLevel, int specialtyID);
int calculate_ward_stay_cost(int wardID, int daysAdmitted);
float calculate_total_bill(int baseConsultationFee, float surcharge, int wardStayCost);
float calculate_age_subsidy_discount(int age, int totalBillValue);

#endif