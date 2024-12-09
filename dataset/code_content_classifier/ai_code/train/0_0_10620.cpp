#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    
    vector<int> happiness1(N);
    vector<int> happiness2(N);
    
    for(int i = 0; i < N; i++) {
        int slices, a, b;
        cin >> slices >> a >> b;
        
        happiness1[i] = slices * a;
        happiness2[i] = slices * b;
    }
    
    sort(happiness1.begin(), happiness1.end(), greater<int>());
    sort(happiness2.begin(), happiness2.end(), greater<int>());
    
    long long totalHappiness = 0;
    
    for(int i = 0; i < N; i++) {
        if(i < N / 2) {
            totalHappiness += happiness1[i];
        } else {
            totalHappiness += happiness2[i];
        }
    }
    
    cout << totalHappiness << endl;
    
    return 0;
}