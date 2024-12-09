#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minDigit(long long x) {
    return *min_element(to_string(x).begin(), to_string(x).end()) - '0';
}

int maxDigit(long long x) {
    return *max_element(to_string(x).begin(), to_string(x).end()) - '0';
}

long long getNextNumber(long long an) {
    return an + minDigit(an) * maxDigit(an);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a1, k;
        cin >> a1 >> k;

        vector<long long> sequence = {a1};
        for (int j = 1; j < k; j++) {
            sequence.push_back(getNextNumber(sequence.back()));
        }

        cout << sequence.back() << endl;
    }

    return 0;
}