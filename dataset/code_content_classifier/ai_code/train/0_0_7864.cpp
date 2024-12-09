#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    int ans = 0;
    
    int i = 0, j = N-1;
    while(i < N && A[i] == sortedA[i]) {
        i++;
    }
    while(j >= 0 && A[j] == sortedA[j]) {
        j--;
    }
    
    while(i < j) {
        if(A[i] > A[i+1]) {
            ans++;
            i++;
        } else {
            i += 2;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}