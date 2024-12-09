#include <iostream>
#include <cmath>

using namespace std;

int countPatties(int level, long long x) {
    if (level == 0) {
        return x > 0 ? 1 : 0;
    }
    
    long long totalLayers = (1LL << (level + 2)) - 3;
    long long middleLayer = (1LL << (level + 1)) - 1;
    
    if (x <= 1) {
        return 0;
    } else if (x <= 1 + middleLayer) {
        return countPatties(level - 1, x - 1);
    } else if (x == 1 + middleLayer + 1) {
        return countPatties(level - 1, middleLayer) + 1;
    } else {
        return countPatties(level - 1, middleLayer) + 1 + countPatties(level - 1, x - middleLayer - 2);
    }
}

int main() {
    int N;
    long long X;
    cin >> N >> X;
    
    int result = countPatties(N, X);
    
    cout << result << endl;
    
    return 0;
}