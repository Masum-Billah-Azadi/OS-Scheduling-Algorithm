#include <stdio.h>

int main() {
    int Process[] = {1, 2, 3, 4};  // Process IDs
    int BT[] = {8, 4, 2, 6};       // Burst Time for each process
    int Priority[] = {3, 1, 4, 2}; // Priority for each process (lower number = higher priority)
    int TA[4], WT[4], n = 4;
    int temp;

    // Sort processes by Priority (lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Priority[i] > Priority[j]) {
                // Swap Priority
                temp = Priority[i];
                Priority[i] = Priority[j];
                Priority[j] = temp;

                // Swap Burst Time
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                // Swap Process IDs
                temp = Process[i];
                Process[i] = Process[j];
                Process[j] = temp;
            }
        }
    }

    // Calculate Turnaround Time and Waiting Time
    int totalTime = 0;
    printf("Process\tPriority\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        totalTime += BT[i];
        TA[i] = totalTime;           // Turnaround Time
        WT[i] = TA[i] - BT[i];       // Waiting Time
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", Process[i], Priority[i], BT[i], TA[i], WT[i]);
    }

    return 0;
}
