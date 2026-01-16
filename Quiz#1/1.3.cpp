#include <stdio.h>

int main() {
    int n = 6;
    float bt[6] = {99.99, 107.9, 143.77, 20.24, 50.55, 66.66};
    int p[6] = {0, 1, 2, 3, 4, 5};
    float wt[6], tat[6], wtavg = 0, tatavg = 0;
    int i, k, temp_p;
    float temp_bt;

    // Sort by burst time (Bubble sort)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                temp_bt = bt[i];
                bt[i] = bt[k];
                bt[k] = temp_bt;
                temp_p = p[i];
                p[i] = p[k];
                p[k] = temp_p;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    wtavg += wt[0];
    tatavg += tat[0];

    // Print results table
    printf("\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\n\tP%d\t\t%.2f\t\t%.2f\t\t%.2f", p[i], bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);

    return 0;
}