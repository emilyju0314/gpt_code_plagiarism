#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    vector<int> sums;
    for(int i=0; i<(1<<N); i++) {
        int sum = 0;
        for(int j=0; j<N; j++) {
            if(i & (1<<j)) {
                sum += A[j];
            }
        }
        sums.push_back(sum);
    }
    
    sort(sums.begin(), sums.end());
    
    int median = sums[(1<<N)/2 - 1];
    cout << median << endl;
    
    return 0;
}