#include <iostream>
#include <string>

using namespace std;

int getSteps(int n) {
    int steps = 0;

    while (n >= 10) {
        string num = to_string(n);
        int max_result = 0;

        for (int i = 1; i < num.size(); i++) {
            int first = stoi(num.substr(0, i));
            int second = stoi(num.substr(i));
            int result = first * second;
            max_result = max(max_result, result);
        }

        n = max_result;
        steps++;

        if (n == 0) {
            return -1;
        }
    }

    return steps;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int N;
        cin >> N;
        cout << getSteps(N) << endl;
    }

    return 0;
}