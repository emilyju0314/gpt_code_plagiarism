#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, I;
    cin >> n >> I;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int k = ceil(log2(a.size())); // number of bits needed to store original array
    
    int min_changes = n;

    for(int l=0; l<=10^9; l++) {
        for(int r=l; r<=10^9; r++) {
            int changes = 0;
            for(int i=0; i<n; i++) {
                if(a[i] < l) {
                    changes++;
                } else if(a[i] > r) {
                    changes++;
                }
            }

            int compressed_k = ceil(log2(r - l + 1)); // number of bits needed to store compressed array
            int compressed_size = n * compressed_k / 8; // size of the compressed file in bytes
            
            if(compressed_size <= I) {
                min_changes = min(min_changes, changes);
            }
        }
    }

    cout << min_changes << endl;

    return 0;
}