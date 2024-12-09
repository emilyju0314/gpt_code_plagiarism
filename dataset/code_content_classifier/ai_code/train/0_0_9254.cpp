#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int stages = 0;
    int weight = 0;
    
    for (int i = 1; i <= N; i++) {
        weight += i;
        if (weight > K*(stages+1)) {
            stages++;
        }
    }
    
    cout << stages << endl;
    
    return 0;
}