#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    priority_queue<int> pq;

    string line;
    while (getline(cin, line)) {
        if (line == "end")
            break;

        stringstream ss(line);
        string operation;
        ss >> operation;

        if (operation == "insert") {
            int num;
            ss >> num;
            pq.push(num);
        } else if (operation == "extract") {
            if (!pq.empty()) {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }

    return 0;
}