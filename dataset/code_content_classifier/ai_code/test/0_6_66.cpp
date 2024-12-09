#include <iostream>
#include <string>

using namespace std;

int lastRemainingCard(int N, int A, int B, string DA, string DB) {
    if (DA == DB) {
        if (DA == "left") {
            return min(A, B);
        } else {
            return max(A, B);
        }
    } else {
        if (DA == "left") {
            return (B - A - 1 + N) % N;
        } else {
            return (A - B - 1 + N) % N;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, A, B;
        string DA, DB;
        cin >> N >> A >> B >> DA >> DB;

        int result = lastRemainingCard(N, A, B, DA, DB);
        cout << result << endl;
    }

    return 0;
}