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
    
    vector<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int odd_count = 0;
        for (int j = i; j < n; j++) {
            freq[a[j]]--;
            if (freq[a[j]] % 2 == 0) {
                odd_count--;
            } else {
                odd_count++;
            }
            if (odd_count <= 1) {
                count++;
            }
        }
        fill(freq.begin(), freq.end(), 0); 
        for (int k = i; k < n; k++) {
            freq[a[k]]++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}