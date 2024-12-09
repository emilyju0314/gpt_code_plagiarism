#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countZigzagsBetween(int A, int B, int M) {
    int count = 0;
    for(int i = A; i <= B; i++) {
        if(i % M == 0) {
            string num = to_string(i);
            bool increasing = true;
            bool decreasing = true;

            for(int j = 1; j < num.length(); j++) {
                if(num[j] < num[j-1]) {
                    increasing = false;
                } else if(num[j] > num[j-1]) {
                    decreasing = false;
                }
            }

            if(increasing || decreasing) {
                count++;
            }
        }
    }
    return count % 10000;
}

int main() {
    int A, B, M;
    cin >> A >> B >> M;

    int result = countZigzagsBetween(A, B, M);
    cout << result << endl;

    return 0;
}