#include <iostream>
#include <vector>

using namespace std;

int n, k, S;
vector<int> cubes;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int countWays(int i, int sum, int exclamationMarks) {
    if (i == n) {
        if (sum == S && exclamationMarks <= k) {
            return 1;
        }
        return 0;
    }
    
    int ways = countWays(i+1, sum, exclamationMarks);
    ways += countWays(i+1, sum + cubes[i], exclamationMarks + 1);
    
    return ways;
}

int main() {
    cin >> n >> k >> S;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cubes.push_back(a);
    }
    
    int totalWays = countWays(0, 0, 0);
    cout << totalWays << endl;
    
    return 0;
}