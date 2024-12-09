#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> W;
    
    vector<int> S(N), T(N);
    
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int X, Y;
    cin >> X >> Y;
    
    // Your code for calculating the minimum possible value of the sum of fatigue degrees goes here
    
    cout << result << endl;
    
    return 0;
}