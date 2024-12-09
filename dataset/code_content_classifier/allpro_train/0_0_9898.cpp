#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countTriples(vector<int>& a, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int z = j+1; z < n; z++) {
                int minVal = min(a[i], min(a[j], a[z]));
                int maxVal = max(a[i], max(a[j], a[z]));
                if(maxVal - minVal <= 2) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int result = countTriples(a, n);
        cout << result << endl;
    }

    return 0;
}