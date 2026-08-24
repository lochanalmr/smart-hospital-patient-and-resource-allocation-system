#include <stdio.h>
#include <stdlib.h>
#include "data_arrays.h"
#include "calculations.h"

int estimatedWaitingTimeCalculator(int patientCount, int specialtyIDs[], int wardIDs[], int countPerSpecialty[]){
    int waitTime = 0;
    int peopleBeforePatient = 0;
    int specialtyOfPatient = 0;

    specialtyOfPatient = specialtyIDs[patientCount];
    peopleBeforePatient = countPerSpecialty[specialtyOfPatient] - 1;
    waitTime = peopleBeforePatient * consultationTimesPerPatient[specialtyOfPatient];

    return waitTime;
}