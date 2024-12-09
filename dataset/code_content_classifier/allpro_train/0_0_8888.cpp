#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, V;
    cin >> N >> K >> V;
    
    vector<int> tanks(N);
    int total_water = 0;
    for(int i = 0; i < N; i++) {
        cin >> tanks[i];
        total_water += tanks[i];
    }
    
    if(total_water < V) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        for(int i = 0; i < N; i++) {
            int transfer = min(V, K);
            if(tanks[i] < transfer) {
                transfer = tanks[i];
            }
            cout << transfer << " " << (i + 1) << " 1" << endl;
            V -= transfer;
        }
    }
    
    return 0;
}