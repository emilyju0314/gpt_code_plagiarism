#include <iostream>
#include <vector>

using namespace std;

int countTrailingZeros(int N, vector<int>& factorial) {
    int count = 0;
    while (factorial.back() % N == 0) {
        count++;
        factorial.back() /= N;
    }
    return count;
}

int main() {
    int N, M;
    
    while (true) {
        cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<int> factorial(1, 1);
        
        for (int i = 1; i <= M; i++) {
            int carry = 0;
            for (int j = 0; j < factorial.size() || carry; j++) {
                if (j == factorial.size()) {
                    factorial.push_back(0);
                }
                long long product = factorial[j] * i + carry;
                factorial[j] = product % N;
                carry = product / N;
            }
        }
        
        cout << countTrailingZeros(N, factorial) << endl;
    }
    
    return 0;
}