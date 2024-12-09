#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

unordered_map<string, int> priorities;
stack<unordered_map<string, int>> changes;

int main() {
    int q;
    cin >> q;

    unordered_map<string, int> initial;
    changes.push(initial);

    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;

        if (operation == "set") {
            string assignment;
            int priority;
            cin >> assignment >> priority;

            priorities[assignment] = priority;
            changes.top()[assignment] = priority;
        } else if (operation == "remove") {
            string assignment;
            cin >> assignment;

            if (priorities.find(assignment) != priorities.end()) {
                priorities.erase(assignment);
                changes.top().erase(assignment);
            }
        } else if (operation == "query") {
            string assignment;
            cin >> assignment;

            if (priorities.find(assignment) != priorities.end()) {
                int count = 0;
                int priority = priorities[assignment];
                for (const auto &it : priorities) {
                    if (it.second < priority) {
                        count++;
                    }
                }
                cout << count << endl;
                cout << flush;
            } else {
                cout << -1 << endl;
                cout << flush;
            }
        } else if (operation == "undo") {
            int days;
            cin >> days;
            for (int j = 0; j < days; j++) {
                for (const auto &it : changes.top()) {
                    priorities.erase(it.first);
                }
                changes.pop();
            }
        }
    }

    return 0;
}