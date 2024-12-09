#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L, Q;
    cin >> N;
    
    vector<int> hotels(N);
    for(int i = 0; i < N; i++) {
        cin >> hotels[i];
    }
    
    cin >> L >> Q;
    
    // Preprocess distances between hotels
    vector<int> dist(N);
    for(int i = 1; i < N; i++) {
        dist[i] = hotels[i] - hotels[i-1];
    }
    
    vector<int> days(N, 0);
    for(int i = 0; i < N; i++) {
        days[i] = (dist[i] + L - 1) / L;
    }
    
    for(int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        
        int days_needed = 0;
        if(a > b) {
            swap(a, b);
        }
        
        for(int i = a-1; i < b-1; i++) {
            days_needed += days[i];
        }
        
        cout << days_needed << endl;
    }

    return 0;
}