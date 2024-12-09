#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    long long sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            sum += (1LL * A[i] * A[j]) % 200003;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}