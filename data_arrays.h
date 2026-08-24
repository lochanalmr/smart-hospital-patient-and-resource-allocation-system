#ifndef DATA_ARRAYS_H
#define DATA_ARRAYS_H

// Doctor specialties data
extern const char *specialtyNames[];
extern const int baseConsultationFees[];
extern const int consultationTimesPerPatient[];
extern const int dailyPatientCaps[];

// Hospital ward data
extern const char *wardNames[];
extern const int dailyBedRates[];
extern const int totalBedCapacities[];

// Bed status tracking array
extern int bedOccupancy[4][20];

#endif