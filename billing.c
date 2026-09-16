#include <stdio.h>
#include "billing.h"
#include "data_arrays.h"

char* triageLevelText(int t){
    switch(t){
        case 1:
            return "Level 1 (Normal)";
        case 2:
            return "Level 2 (Urgent)";
        case 3:
            return "Level 3 (Critical)";
        default:
            return "Unknown";
    }
}

float surchargePercentage(int t){
    if (t == 2)
        return 20.0;
    else if (t == 3)
        return 50.0;
    else
        return 0.0;
}

void displayPatientBill(int patientNo, char name[], int age, int triageLevel,
    int specialtyID, int admitted, int wardID, int bedNumber, int daysAdmitted,
    int baseConsultationFee, float surcharge, int wardStayCost,
    float totalBillValue, float ageSubsidyDiscount,
    float finalAmountPayable, int waitTime){

    int subsidyEligible = (age < 0 || age > 65);

    printf("=====================================================\n");
    printf("        SMART HOSPITAL ADMISSION & BILL\n");
    printf("-----------------------------------------------------\n");
    printf("Patient ID       : PAT-%04d\n", patientNo);
    printf("Patient Name     : %s\n", name);
    printf("Age              : %d Years%s\n", age, subsidyEligible ? " (15% Subsidy Eligible)" : " (Subsidy Not Eligible)");
    printf("Specialty        : %s\n", specialtyNames[specialtyID - 1]);
    if (admitted == 1)
        printf("Assigned Ward    : %s (Bed #%02d)\n", wardNames[wardID - 1], bedNumber);
    else
        printf("Assigned Ward    : Not Admitted\n");
    printf("Urgency Level    : %s\n", triageLevelText(triageLevel));
    printf("-----------------------------------------------------\n");
    printf("Base Consultation Fee   : LKR %10.2f\n", (float)baseConsultationFee);
    printf("Emergency Surcharge     : LKR %10.2f (%.0f%%)\n", surcharge, surchargePercentage(triageLevel));
    printf("Ward Stay Cost (%d Days) : LKR %10.2f\n", daysAdmitted, (float)wardStayCost);
    printf("-----------------------------------------------------\n");
    printf("Gross Total Bill        : LKR %10.2f\n", totalBillValue);
    printf("Age Subsidy Discount    : LKR %10.2f (%.0f%%)\n", -ageSubsidyDiscount, subsidyEligible ? 15.0 : 0.0);
    printf("-----------------------------------------------------\n");
    printf("Final Payable Amount    : LKR %10.2f\n", finalAmountPayable);
    printf("Estimated Waiting Time  : %d mins%s\n", waitTime, waitTime == 0 ? " (Immediate Attention)" : " (Not Immediate Attention)");
    printf("=====================================================\n");
}
