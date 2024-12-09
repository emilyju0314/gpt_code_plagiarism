#include <iostream>
#include <vector>
using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> occurrences(n + 1, 0);
        for(int i = 1; i < n; i++) {
            int remainder = (i * i) % n;
            occurrences[remainder]++;
        }

        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int diff = abs(i - j);
                if(diff > n / 2) diff = n - diff;
                occurrences[diff]++;
            }
        }

        for(int i = 1; i <= n / 2; i++) {
            cout << occurrences[i] << endl;
        }
    }

    return 0;
}