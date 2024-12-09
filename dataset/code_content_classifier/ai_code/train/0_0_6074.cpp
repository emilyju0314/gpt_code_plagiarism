#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> memory;
    vector<int> coffees;

    for (int i = 1; i <= n; ++i) {
        coffees.push_back(i);
    }

    int total_queries = 0;

    while (true) {
        for (int i = 0; i < n; i++) {
            cout << "? " << coffees[i] << endl;
            cout.flush();

            string response;
            cin >> response;

            if (response == "Y") {
                memory.push_back(coffees[i]);
            }

            total_queries++;
        }

        if (memory.size() >= k) {
            break;
        }

        cout << "R" << endl;
        cout.flush();
    }

    sort(memory.begin(), memory.end());
    int d = 1;

    for (int i = 1; i < memory.size(); ++i) {
        if (memory[i] != memory[i - 1]) {
            d++;
        }
    }

    cout << "! " << d << endl;
    cout.flush();

    return 0;
}