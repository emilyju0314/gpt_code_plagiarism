#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> permutation(n);
    for(int i=0; i<n; i++) {
        cin >> permutation[i];
    }

    int inversions = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(permutation[i] > permutation[j]) {
                inversions++;
            }
        }
    }

    double expected_inversions = 0.0;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(permutation[a-1] > permutation[b-1]) {
            expected_inversions++;
        }
    }

    double total_inversions = inversions + expected_inversions * ((n * (n-1)) / 2.0);
    double average_inversions = total_inversions / m;

    cout << average_inversions << endl;

    return 0;
}