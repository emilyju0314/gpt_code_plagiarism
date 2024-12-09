#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long max_sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            // Check if students i and j can work calmly together
            if((a[i] & a[j]) == 0) {
                int sum = b[i] + b[j];
                max_sum = max(max_sum, sum);
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}