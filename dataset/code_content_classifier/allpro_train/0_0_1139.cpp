#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<bool> read(n, false);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--; // Adjust to 0-based indexing
    }

    int days = 0;
    for(int i = 0; i < n; i++) {
        if(!read[i]) {
            days++;
            int curr = i;
            while(!read[curr]) {
                read[curr] = true;
                curr = a[curr];
            }
        }
    }

    cout << days << endl;

    return 0;
}