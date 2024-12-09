#include <iostream>
#include <queue>

using namespace std;

struct Process {
    string name;
    int time;
};

int main() {
    int n, q;
    cin >> n >> q;

    queue<Process> processes;
    for (int i = 0; i < n; i++) {
        Process p;
        cin >> p.name >> p.time;
        processes.push(p);
    }

    int current_time = 0;
    while (!processes.empty()) {
        Process p = processes.front();
        processes.pop();
        if (p.time > q) {
            current_time += q;
            p.time -= q;
            processes.push(p);
        } else {
            current_time += p.time;
            cout << p.name << " " << current_time << endl;
        }
    }

    return 0;
}