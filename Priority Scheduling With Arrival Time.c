#include <stdio.h>

int main() {
    int n = 5; // Number of processes
    int Process[] = {1, 2, 3, 4, 5};  // Process IDs
    int AT[] = {4, 1, 2, 3, 0};       // Arrival Time
    int BT[] = {8, 4, 2, 1, 7};       // Burst Time
    int OriginalBT[] = {8, 4, 2, 1, 7}; // Copy of Burst Time for printing purposes
    int Priority[] = {3, 1, 4, 2, 6}; // Priority (lower number = higher priority)
    int WT[5], TA[5];                 // Waiting Time and Turnaround Time
    int CT[5];                        // Completion Time
    int completed = 0, time = 0, index, minPriority;

    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        minPriority = 9999; // To find the process with the highest priority
        index = -1;

        // Find the highest priority process that has arrived and is not yet completed
        for (int i = 0; i < n; i++) {
            if (AT[i] <= time && Priority[i] < minPriority && BT[i] > 0) {
                minPriority = Priority[i];
                index = i;
            }
        }

        if (index != -1) {
            // Process execution
            time += BT[index];  // Add burst time to current time
            CT[index] = time;   // Completion time of the current process
            TA[index] = CT[index] - AT[index]; // Turnaround Time = Completion Time - Arrival Time
            WT[index] = TA[index] - OriginalBT[index]; // Waiting Time = Turnaround Time - Original Burst Time
            BT[index] = 0;      // Mark process as completed
            completed++;
            
            // Print process information
            printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                   Process[index], AT[index], OriginalBT[index], Priority[index], CT[index], TA[index], WT[index]);
        } else {
            time++; // Increment time if no process is ready to execute
        }
    }

    return 0;
}