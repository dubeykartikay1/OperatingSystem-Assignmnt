#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
};

// priority
bool priorityCompare(Process a, Process b) {
    if (a.arrivalTime == b.arrivalTime)
        return a.priority < b.priority;
    return a.arrivalTime < b.arrivalTime;
}

// sjf
bool sjfCompare(Process a, Process b) {
    if (a.arrivalTime == b.arrivalTime)
        return a.burstTime < b.burstTime;
    return a.arrivalTime < b.arrivalTime;
}

//ljf
bool ljfCompare(Process a, Process b) {
    if (a.arrivalTime == b.arrivalTime)
        return a.burstTime > b.burstTime;
    return a.arrivalTime < b.arrivalTime;
}

void calculateTimes(vector<Process> &processes) {
    int n = processes.size();
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime > currentTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
}

void printProcesses(vector<Process> &processes) {
    cout << "PID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n";
    for (auto &p : processes) {
        cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" 
             << p.priority << "\t\t" << p.waitingTime << "\t" << p.turnAroundTime << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter details for process " << i + 1 << ":\n";
        processes[i].pid = i + 1;
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "Priority: ";
        cin >> processes[i].priority;
    }

    // priority 
    cout << "\nPriority Scheduling:\n";
    sort(processes.begin(), processes.end(), priorityCompare);
    calculateTimes(processes);
    printProcesses(processes);

    // sjf 
    cout << "\nShortest Job First (SJF) Scheduling:\n";
    sort(processes.begin(), processes.end(), sjfCompare);
    calculateTimes(processes);
    printProcesses(processes);

    // ljf 
    cout << "\nLongest Job First (LJF) Scheduling:\n";
    sort(processes.begin(), processes.end(), ljfCompare);
    calculateTimes(processes);
    printProcesses(processes);

    return 0;
}
