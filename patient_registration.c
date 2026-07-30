#include <stdio.h>
#include <string.h>

void patient_registration(char name[], int size, int *age, int *triageLevel, int *specialtyID, int *admitted, int *wardID, int *daysAdmitted){
    printf("---Patient Registration---\n");

    printf("1 - Patient Details Collection\n");
    printf("Enter patient name: ");
    scanf("%s", name);
    printf("Enter patient age: ");
    scanf("%d", age);
    printf("Emergency triage level (1 = Normal, 2 = Urgent, 3 = Critical): ");
    scanf("%d", triageLevel);

    printf("\n2 - Specialty selection\n");
    printf("Specialty ID (1 - 4): ");
    scanf("%d", specialtyID);

    printf("\n3 - Ward Admission Details\n");
    printf("Is admitted to ward? (1 = Yes, 0 = No): ");
    scanf("%d", admitted);
    if (admitted == 0){
        printf("Enter ward ID (1 to 4): ");
        scanf("%d", wardID);
        printf("Enter days admitted: ");
        scanf("%d", daysAdmitted);
    }
    else if(admitted == 1){
        daysAdmitted = 0;
    }
}