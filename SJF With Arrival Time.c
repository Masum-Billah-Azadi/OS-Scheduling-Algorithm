#include <stdio.h>

int main() {
    int Process[] = {1, 2, 3, 4};  // Process IDs
    int AT[] = {0, 1, 2, 3};       // Arrival Time for each process
    int BT[] = {6, 2, 8, 3};       // Burst Time for each process
    int TA[4], WT[4], n = 4;
    int completed = 0, time = 0, minBT, index;
    int done[4] = {0};             // Track completed processes

    printf("Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    while (completed < n) {
        minBT = 9999;
        index = -1;

        // Find the process with the shortest Burst Time that's ready
        for (int i = 0; i < n; i++) {
            if (AT[i] <= time && !done[i] && BT[i] < minBT) {
                minBT = BT[i];
                index = i;
            }
        }

        if (index != -1) {
            time += BT[index];                // Update current time
            TA[index] = time - AT[index];     // Turnaround Time
            WT[index] = TA[index] - BT[index]; // Waiting Time
            done[index] = 1;                  // Mark process as done
            completed++;

            printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", Process[index], AT[index], BT[index], TA[index], WT[index]);
        } else {
            time++; // If no process is ready, increment time
        }
    }

    return 0;
}
