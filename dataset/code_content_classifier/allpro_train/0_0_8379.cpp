#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    int count = 0;
    int current_min = N;
    
    for(int i = 0; i < N; i++) {
        if(P[i] <= current_min) {
            count++;
            current_min = P[i];
        }
    }
    
    cout << count << endl;
    
    return 0;
}