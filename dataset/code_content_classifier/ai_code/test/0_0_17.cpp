#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

        vector<int> b;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                b.push_back(a[i]);
            } else {
                b.insert(b.begin(), a[i]);
            }
        }

        // Calculate number of inversions
        int inversions = 0;
        for(int i = 0; i < b.size(); i++) {
            for(int j = i + 1; j < b.size(); j++) {
                if(b[i] > b[j]) {
                    inversions++;
                }
            }
        }

        cout << inversions << endl;
    }

    return 0;
}