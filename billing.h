#ifndef BILLING_H_INCLUDED
#define BILLING_H_INCLUDED

void displayPatientBill(int patientNo, char name[], int age, int triageLevel,
    int specialtyID, int admitted, int wardID, int bedNumber, int daysAdmitted,
    int baseConsultationFee, float surcharge, int wardStayCost,
    float totalBillValue, float ageSubsidyDiscount,
    float finalAmountPayable, int waitTime);

#endif // BILLING_H_INCLUDED
