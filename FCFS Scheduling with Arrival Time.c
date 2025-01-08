#include <stdio.h>

int main() {
    int Process[] = {1, 2, 3, 4}; // Process IDs
    int AT[] = {0, 1, 2, 3};      // Arrival Time for each process
    int BT[] = {3, 4, 2, 5};      // Burst Time for each process
    int TA[4], WT[4];             // Arrays for Turnaround Time and Waiting Time
    int temp = 0;                 // Temporary variable to calculate times

    // Display Processes, Arrival Time, and Burst Time
    printf("Process\tArrival Time\tBurst Time\n");
    for (int i = 0; i < 4; i++) {
        printf("P%d\t\t%d\t\t%d\n", Process[i], AT[i], BT[i]);
    }

    // Calculate Turnaround Time and Waiting Time
    printf("\nTurnaround Time:\n");
    for (int i = 0; i < 4; i++) {
        if (temp < AT[i]) {
            temp = AT[i]; // Wait for the process if it hasn't arrived yet
        }
        temp += BT[i];       // Add burst time to cumulative total
        TA[i] = temp - AT[i]; // Turnaround Time = Completion Time - Arrival Time
        WT[i] = TA[i] - BT[i]; // Waiting Time = Turnaround Time - Burst Time
        printf("P%d: %d\n", Process[i], TA[i]); // Display Turnaround Time
    }

    // Display Waiting Time
    printf("\nWaiting Time:\n");
    for (int i = 0; i < 4; i++) {
        printf("P%d: %d\n", Process[i], WT[i]);
    }

    return 0;
}
