#include <iostream>
#include <cmath>

using namespace std;

pair<int, int> findPair(long long r) {
    long long x, y;
    for (x = 1; x <= sqrt(r); x++) {
        if ((r - x - 1) % (x + 1) == 0) {
            y = (r - x - 1) / (x + 1);
            return make_pair(x, y);
        }
    }
    return make_pair(-1, -1);
}

int main() {
    long long r;
    cin >> r;
    
    pair<int, int> result = findPair(r);
    
    if (result.first == -1) {
        cout << "NO";
    } else {
        cout << result.first << " " << result.second;
    }
    
    return 0;
}