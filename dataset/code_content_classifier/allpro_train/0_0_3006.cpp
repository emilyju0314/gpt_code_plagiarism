#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int min_balls = K * (K + 1) / 2;
    int max_balls = N * K - min_balls;
    
    cout << max_balls - min_balls << endl;
    
    return 0;
}