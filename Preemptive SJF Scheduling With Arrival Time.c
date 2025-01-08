#include <stdio.h>

int main() {
    int n = 4; // Number of processes
    int Process[] = {1, 2, 3, 4};  // Process IDs
    int AT[] = {0, 1, 2, 3};       // Arrival Time
    int BT[] = {8, 4, 2, 1};       // Burst Time (remaining burst time will be updated)
    int RT[4];                     // Remaining Burst Time
    int WT[4], TA[4];              // Waiting Time and Turnaround Time
    int completed = 0, time = 0, minBT, index;
    int isProcessing = 0;          // Flag to check if a process is currently running

    // Copy Burst Time into Remaining Time
    for (int i = 0; i < n; i++) {
        RT[i] = BT[i];
    }

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        minBT = 9999;
        index = -1;

        // Find the process with the shortest remaining burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (AT[i] <= time && RT[i] > 0 && RT[i] < minBT) {
                minBT = RT[i];
                index = i;
            }
        }

        if (index != -1) {
            // Process found; execute it for 1 time unit
            RT[index]--;
            time++;

            // If process completes
            if (RT[index] == 0) {
                completed++;
                int completionTime = time;
                TA[index] = completionTime - AT[index];  // Turnaround Time
                WT[index] = TA[index] - BT[index];       // Waiting Time

                printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                       Process[index], AT[index], BT[index], completionTime, TA[index], WT[index]);
            }
        } else {
            time++; // Increment time if no process is ready
        }
    }

    return 0;
}
