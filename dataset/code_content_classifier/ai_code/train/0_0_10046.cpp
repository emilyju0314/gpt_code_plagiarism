#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i];
    }
    
    int odd = 0, even = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    
    if (odd == 0 || even == 0) {
        cout << 0 << endl;
    } else {
        cout << N - 2 << endl;
    }
    
    return 0;
}