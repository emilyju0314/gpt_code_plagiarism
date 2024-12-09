#include <iostream>
#include <string>

using namespace std;

int countNonZeroDigits(int n, int k) {
    string num = to_string(n);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int nonZeroCount = 0;
        string currentNum = to_string(i);
        for (char c : currentNum) {
            if (c != '0') {
                nonZeroCount++;
            }
        }
        if (nonZeroCount == k) {
            count++;
        }
    }
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    cout << countNonZeroDigits(N, K) << endl;

    return 0;
}