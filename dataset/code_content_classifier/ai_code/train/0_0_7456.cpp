#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        while(a[i] > 0) {
            freq[a[i]]++;
            a[i] /= 2;
        }
    }

    int min_ops = n * 10; // initialize with a large number
    for(auto &[num, count] : freq) {
        if(count >= k) {
            int ops = 0;
            int remaining = count;
            for(auto &[num2, count2] : freq) {
                while(num2 > num && remaining < k) {
                    remaining += count2;
                    ops++;
                    num2 /= 2;
                }
            }
            min_ops = min(min_ops, ops);
        }
    }

    cout << min_ops << endl;

    return 0;
}