#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, d1, d2;
    cin >> N >> d1 >> d2;
    
    vector<pair<int, int>> A(N);
    vector<pair<int, int>> B(N);
    
    for(int i=0; i<N; i++) {
        cin >> A[i].first >> A[i].second >> B[i].first >> B[i].second;
    }
    
    int count = 0;
    bool last_greater_than_d2 = true;
    
    for(int i=0; i<N; i++) {
        int distance = pow((A[i].first - B[i].first), 2) + pow((A[i].second - B[i].second), 2);
        
        if (distance <= pow(d1, 2) && last_greater_than_d2) {
            count++;
        }
        
        if (distance > pow(d2, 2)) {
            last_greater_than_d2 = true;
        } else {
            last_greater_than_d2 = false;
        }
    }
    
    cout << count << endl;
    
    return 0;
}