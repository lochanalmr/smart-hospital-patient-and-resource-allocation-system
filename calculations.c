#include <stdio.h>
#include <stdlib.h>
#include "data_arrays.h"
#include "calculations.h"

int calculate_estimated_waiting_time(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]){
    int waitTime = 0;
    int peopleBeforePatient = 0;
    int specialtyOfPatient = 0;

    specialtyOfPatient = specialtyIDs[patientCount];
    peopleBeforePatient = countPerSpecialty[specialtyOfPatient] - 1;
    waitTime = peopleBeforePatient * consultationTimesPerPatient[specialtyOfPatient];

    return waitTime;
}

float calculate_emergency_surcharge(int triageLevel, int specialtyID){
    float surcharge = 0;
    if (triageLevel == 1){
        surcharge = 0;
    }
    else if (triageLevel == 2){
        surcharge = (float) baseConsultationFees[specialtyID - 1] * 0.2;
    }
    else if (triageLevel == 3){
        surcharge = (float) baseConsultationFees[specialtyID - 1] * 0.5;
    }
    return surcharge;
}

float calculate_ward_stay_cost(int wardID, int daysAdmitted){
    //
}