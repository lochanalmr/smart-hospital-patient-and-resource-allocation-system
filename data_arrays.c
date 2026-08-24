#include "data_arrays.h"

// Doctor specialties data
const char *specialtyNames[] = {
    "General Practice (OPD)",
    "Pediatrics",
    "Cardiology",
    "Neurology"
};

const int baseConsultationFees[] = {
    1500,
    2500,
    4500,
    5000
};

const int consultationTimesPerPatient[] = {
    15,
    20,
    30,
    30
};

const int dailyPatientCaps[] = {
    30,
    20,
    12,
    10
};

// Hospital ward data
const char *wardNames[] = {
    "General Ward",
    "Pediatric Ward",
    "Surgical Ward",
    "ICU (Intensive Care Unit)"
};

const int dailyBedRates[] = {
    3000,
    6000,
    12000,
    25000
};

const int totalBedCapacities[] = {
    20,
    10,
    10,
    5
};

// Bed status tracking array
int bedOccupancy[4][20] = {0};
