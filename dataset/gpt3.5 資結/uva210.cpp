#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int quantum;
    string state;
    int block_time;
    int block_device;
};

map<string, int> label_to_line;
vector<string> code;
vector<Process> processes;
queue<Process> ready_queue;
vector<queue<Process>> block_queues;
vector<int> register_file(26, 0);
int current_process = -1;
int current_line = 0;

void execute_instruction(Process& process) {
    if (current_line == code.size() || process.state != "READY") {
        process.quantum = 0;
        return;
    }

    string instruction = code[current_line];
    istringstream iss(instruction);
    string op;
    char reg;
    int val;

    iss >> op;
    if (op[0] == '=' || op == "print") {
        reg = op[0];
        iss >> val;
    }
    else {
        iss >> reg >> val;
    }

    if (op == "lock") {
        process.state = "BLOCKED";
        process.block_device = val;
        process.block_time = val;
        current_process = -1;
        block_queues[val].push(process);
        return;
    }
    else if (op == "unlock") {
        if (!block_queues[val].empty()) {
            Process next_process = block_queues[val].front();
            block_queues[val].pop();
            next_process.state = "READY";
            ready_queue.push(next_process);
        }
    }
    else if (op == "end") {
        process.state = "TERMINATED";
    }
    else {
        if (op == "print") {
            cout << process.id << ": " << register_file[reg - 'a'] << endl;
        }
        else {
            if (op == "goto") {
                current_line = label_to_line[op];
                return;
            }

            if (op == "==" && register_file[reg - 'a'] == val) {
                current_line = label_to_line[op];
                return;
            }

            if (op == "!=" && register_file[reg - 'a'] != val) {
                current_line = label_to_line[op];
                return;
            }

            if (op == "<=" && register_file[reg - 'a'] <= val) {
                current_line = label_to_line[op];
                return;
            }

            if (op == "<" && register_file[reg - 'a'] < val) {
                current_line = label_to_line[op];
                return;
            }

            if (op == ">=" && register_file[reg - 'a'] >= val) {
                current_line = label_to_line[op];
                return;
            }

            if (op == ">" && register_file[reg - 'a'] > val) {
                current_line = label_to_line[op];
                return;
            }

            if (op == "=") {
                register_file[reg - 'a'] = val;
            }
            else {
                register_file[reg - 'a'] += val;
            }
        }
    }

    current_line++;
    process.quantum--;

    if (process.quantum == 0) {
        process.state = "READY";
        ready_queue.push(process);
    }
}

int main() {
    int n, r, quantum;
    cin >> n >> r >> quantum;

    code.resize(n);
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin >> ws, line);
        code[i] = line;
        if (line.substr(2, 5) == "label") {
            label_to_line[line.substr(0, 2)] = i;
        }
    }

    block_queues.resize(r);

    for (int i = 0; i < r; i++) {
        Process process;
        process.id = i + 1;
        process.quantum = quantum;
        process.state = "READY";
        process.block_time = 0;
        process.block_device = -1;
        processes.push_back(process);
        ready_queue.push(process);
    }

    while (!ready_queue.empty()) {
        Process current_process = ready_queue.front();
        ready_queue.pop();

        if (current_process.state == "TERMINATED") {
            continue;
        }

        current_line = 0;
        while (current_process.state != "TERMINATED" && current_process.quantum > 0) {
            execute_instruction(current_process);
        }
    }

    return 0;
}