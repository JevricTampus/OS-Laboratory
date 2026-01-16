#include <stdio.h>

int main() {
    int n = 10;
    int bt[10] = {9, 8, 7, 8, 7, 8, 2, 1, 2, 5};
    int p[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float wt[10], tat[10], wtavg = 0, tatavg = 0;
    int i;

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
        printf("\n\tP%d\t\t%d\t\t%.2f\t\t%.2f", p[i], bt[i], wt[i], tat[i]);

    printf("\n\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);

    return 0;
}
