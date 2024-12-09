#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countOnes(string s) {
    int count = 0;
    for(char c : s) {
        if(c == '1') {
            count++;
        }
    }
    return count;
}

int main() {
    int Q;
    cin >> Q;

    while(Q--) {
        int n;
        cin >> n;

        vector<string> strings(n);
        vector<int> counts(n);

        for(int i = 0; i < n; i++) {
            cin >> strings[i];
            counts[i] = countOnes(strings[i]);
        }

        int evenCount = 0, oddCount = 0, pairCount = 0;
        for(int count : counts) {
            if(count % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(counts[i] % 2 == 1) {
                for(int j = i + 1; j < n; j++) {
                    if(counts[j] % 2 == 1) {
                        pairCount++;
                        break;
                    }
                }
            }
        }

        cout << evenCount + pairCount << endl;
    }

    return 0;
}