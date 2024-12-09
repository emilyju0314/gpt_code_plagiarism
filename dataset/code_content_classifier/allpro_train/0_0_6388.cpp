#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    long long count = 0;
    while(true) {
        long long max_element = *max_element(a.begin(), a.end());
        int index = max_element % N;
        long long diff = max_element - index;
        
        if (max_element >= (N-1)) {
            break;
        }
        
        count++;

        for (int i = 0; i < N; i++) {
            if (i == index) {
                a[i] = index;
            } else {
                a[i] += 1;
            }
        }
    }

    cout << count << endl;

    return 0;
}