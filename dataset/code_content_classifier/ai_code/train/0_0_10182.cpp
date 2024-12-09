#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> operations;

    for(int i = 0; i < n; i++) {
        string op;
        int num;
        cin >> op >> num;
        operations.push_back({op, num});
    }

    vector<pair<string, int>> correctedOperations;

    for(int i = 0; i < n; i++) {
        if(operations[i].first == "getMin") {
            correctedOperations.push_back({"removeMin", 0});
            correctedOperations.push_back({"insert", operations[i].second});
        } else {
            correctedOperations.push_back(operations[i]);
        }
    }

    cout << correctedOperations.size() << endl;
    for(auto op : correctedOperations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}