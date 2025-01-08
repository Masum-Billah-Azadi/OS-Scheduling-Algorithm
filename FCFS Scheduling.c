#include <stdio.h>

int main() {
    int Process[] = {1, 2, 3, 4}; // Process IDs
    int BT[] = {3, 4, 2, 5};     // Burst Time for each process
    int TA[4], WT[4];            // Arrays for Turnaround Time and Waiting Time
    int temp = 0;                // Temporary variable to calculate times

    // Display processes
    printf("Processes:\n");
    for (int i = 0; i < 4; i++) {
        printf("P%d\n", Process[i]);
    }

    // Display Burst Time
    printf("Burst Time:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\n", BT[i]);
    }

    // Calculate Turnaround Time and Waiting Time
    printf("Turnaround Time:\n");
    for (int i = 0; i < 4; i++) {
        temp += BT[i];         // Add burst time to cumulative total
        TA[i] = temp;          // Turnaround Time
        WT[i] = TA[i] - BT[i]; // Waiting Time
        printf("%d\n", TA[i]); // Display Turnaround Time
    }

    // Display Waiting Time
    printf("Waiting Time:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d\n", WT[i]);
    }

    return 0;
}
