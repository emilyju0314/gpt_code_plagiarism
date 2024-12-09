#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_inversions = 0;
    int min_x = 0;
    
    for (int k = 29; k >= 0; k--) {
        int x = min_x | (1 << k);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] ^ x;
        }
        
        int inversions = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (b[i] > b[j]) {
                    inversions++;
                }
            }
        }
        
        if (inversions < min_inversions || min_inversions == 0) {
            min_x = x;
            min_inversions = inversions;
        }
    }

    cout << min_inversions << " " << min_x << endl;

    return 0;
}