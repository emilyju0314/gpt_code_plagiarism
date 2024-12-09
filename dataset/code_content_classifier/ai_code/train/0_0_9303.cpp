#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    
    int T;
    cin >> T;
    
    sort(times.begin(), times.end());
    
    int max_students = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (times[j] - times[i] <= T) {
                max_students = max(max_students, j - i + 1);
            }
        }
    }
    
    cout << max_students << endl;
    
    return 0;
}