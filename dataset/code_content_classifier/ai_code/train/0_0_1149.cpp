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

        vector<int> permutation(n);

        for(int i = 0; i < n-1; i++) {
            int k;
            cin >> k;
            vector<int> segment(k);

            for(int j = 0; j < k; j++) {
                cin >> segment[j];
            }

            sort(segment.begin(), segment.end());

            int index = 0;
            for(int j = 0; j < n; j++) {
                if(find(segment.begin(), segment.end(), j+1) == segment.end()) {
                    permutation[index] = j+1;
                    index++;
                }
            }
        }

        permutation[n-1] = 1; // The last element would be the only remaining number

        for(int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }

        cout << endl;
    }

    return 0;
}