#ifndef CALCULATIONS_H_INCLUDED
#define CALCULATIONS_H_INCLUDED

int calculateEstimatedWaitingTime(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]);
float calculateEmergencySurcharge(int triageLevel, int specialtyID);
int calculateWardStayCost(int wardID, int daysAdmitted);
float calculateTotalBill(int baseConsultationFee, float surcharge, int wardStayCost);
float calculateAgeSubsidyDiscount(int age, int totalBillValue);

#endif // CALCULATIONS_H_INCLUDED