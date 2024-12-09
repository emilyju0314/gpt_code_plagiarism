#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> bridges(N-1, 1); // Initialize all bridges to 1
    vector<int> a(M), b(M);
    
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        for(int j = a[i]-1; j < b[i]-1; j++) {
            bridges[j] = 0; // Set bridge between a_i and b_i to 0
        }
    }
    
    int min_removed = 0;
    for(int i = 0; i < N-1; i++) {
        min_removed += bridges[i]; // Count the number of bridges that must be removed
    }
    
    cout << min_removed << endl;
    
    return 0;
}