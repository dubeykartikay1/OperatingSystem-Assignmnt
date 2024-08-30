#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[]) {
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + bt[i - 1];
        wt[i] = service_time[i] - at[i];
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findCompletionTime(int processes[], int n, int tat[], int at[], int ct[]) {
    for (int i = 0; i < n; i++) {
        ct[i] = tat[i] + at[i];
    }
}

void findavgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], ct[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, at, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    findCompletionTime(processes, n, tat, at, ct);

    cout << "Processes  Arrival Time  Burst Time  Completion Time  Turn Around Time  Waiting Time\n";

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "   " << i + 1 << "\t\t" << at[i] << "\t\t"
             << bt[i] << "\t\t" << ct[i] << "\t\t"
             << tat[i] << "\t\t" << wt[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n << endl;
    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n];
    int burst_time[n];
    int arrival_time[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;  // Automatically assign process IDs starting from 1
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time for process " << processes[i] << ": ";
        cin >> arrival_time[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for process " << processes[i] << ": ";
        cin >> burst_time[i];
    }

    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}
