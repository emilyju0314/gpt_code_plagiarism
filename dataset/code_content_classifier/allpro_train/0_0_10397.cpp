#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count = 0;
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            if (sum < t) {
                count++;
            }
        }
    }
    
    cout << count << endl;

    return 0;
}