#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> count;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            count[a[i]] = i+1;
        }

        int pairs = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(a[i] * a[j] == i + j + 2) {
                    pairs++;
                }
            }
        }

        cout << pairs << endl;
    }

    return 0;
}