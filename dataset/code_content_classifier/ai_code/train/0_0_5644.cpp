#include <iostream>
#include <string>

using namespace std;

long long countValidPairs(int A, int B) {
    long long count = 0;
    for (int a = 1; a <= A; a++) {
        for (int b = 1; b <= B; b++) {
            string conc = to_string(a) + to_string(b);
            if ((a * b + a + b) == stoll(conc)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int A, B;
        cin >> A >> B;
        
        cout << countValidPairs(A, B) << endl;
    }
    
    return 0;
}