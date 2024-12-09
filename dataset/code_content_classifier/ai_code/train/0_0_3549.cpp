#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    int max_num = 0;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
        max_num = max(max_num, A[i]);
    }
    
    long long sum = 0;
    
    for(int i=0; i<N; i++){
        sum += A[i];
    }
    
    cout << sum - max_num << endl;
    
    return 0;
}