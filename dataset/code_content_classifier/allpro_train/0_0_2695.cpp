#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> count;
    
    for (int i = 0; i < n; i++) {
        int drink;
        cin >> drink;
        count[drink]++;
    }

    int total_students = 0;

    for (auto it : count) {
        total_students += it.second / 2 * 2;
    }

    total_students += (n - total_students) / 2;

    cout << total_students << endl;

    return 0;
}