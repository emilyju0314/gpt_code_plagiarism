#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int n;
        cin >> n;

        vector<int> segments(n);
        for(int i = 0; i < n; i++) {
            cin >> segments[i];
        }

        int coverage = 0;
        int current_end = 0;

        for(int i = 0; i < n; i++) {
            int new_end1 = current_end - segments[i];
            int new_end2 = current_end + segments[i];

            current_end = max(new_end1, new_end2);
            coverage = max(coverage, current_end);
        }

        cout << coverage << endl;
    }

    return 0;
}