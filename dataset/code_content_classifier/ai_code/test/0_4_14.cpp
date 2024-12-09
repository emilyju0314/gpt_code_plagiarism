#include <iostream>
#include <vector>

using namespace std;

void cyclicShift(vector<int>& arr, int l, int r, int d) {
    vector<int> segment;
    for (int i = l - 1; i < r; i++) {
        segment.push_back(arr[i]);
    }
    d = d % segment.size();
    for (int i = l - 1; i < r; i++) {
        arr[i] = segment[(i - l + d + segment.size()) % segment.size()];
    }
}

void printCyclicShifts(vector<int>& arr) {
    int n = arr.size();
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << "1 " << n << " " << i << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> sorted(a);
        sort(sorted.begin(), sorted.end());

        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == sorted[k]) {
                k++;
            }
        }

        printCyclicShifts(a);
    }

    return 0;
}