#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    long long even_count = 1, odd_count = 1;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            even_count *= 2;
        } else {
            odd_count *= 2;
        }
    }
    
    long long total_count = even_count + odd_count;
    
    cout << total_count << endl;
    
    return 0;
}