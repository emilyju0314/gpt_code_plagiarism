#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long M = 10004205361450474;
    long long x = 1; // Initial guess for hidden number

    // Binary search for hidden number x
    long long left = 1, right = M;
    while (left <= right) {
        long long mid = (left + right) / 2;
        vector<long long> query;
        for (long long i = left; i <= mid; i++) {
            query.push_back(i);
        }
        cout << query.size() << " ";
        for (long long i : query) {
            cout << i << " ";
        }
        cout << endl;
        cout.flush();

        int result;
        cin >> result;

        if (result == 0) {
            right = mid - 1;
        } else if (result == query.size()) {
            left = mid + 1;
        } else {
            cout << query.size() - 1 << " ";
            for (long long i = 0; i < result; i++) {
                cout << query[i] << " ";
            }
            cout << endl;
            cout.flush();

            int answer;
            cin >> answer;
            return 0;
        }
    }

    return 0;
}