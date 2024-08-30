#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[], int ct[]) {
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = ct[i - 1];  // service time is the completion time of the previous process
        wt[i] = service_time[i] - at[i];

        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findCompletionTime(int processes[], int n, int bt[], int at[], int ct[]) {
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], ct[n];
    findCompletionTime(processes, n, bt, at, ct);
    findWaitingTime(processes, n, bt, at, wt, ct);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes  " << "Arrival Time  " << "Burst Time  "
         << "Completion Time  " << "Turn Around Time  "
         << "Waiting Time\n";

    for (int i = 0; i < n; i++) {
        cout << "   " << processes[i] << "\t\t" << at[i] << "\t\t"
             << bt[i] << "\t\t" << ct[i] << "\t\t"
             << tat[i] << "\t\t" << wt[i] << endl;
    }
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];

    int arrival_time[] = {0, 1, 5, 6};
    int burst_time[] = {2, 2, 3, 4};

    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}

