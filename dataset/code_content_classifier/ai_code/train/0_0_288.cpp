#include <iostream>
#include <vector>

using namespace std;

int countInversions(vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        vector<int> temp = a;
        for (int j = 0; j < q; j++) {
            vector<int> subarray;
            for (int k = 0; k < temp.size(); k += (1 << (j+1))) {
                for (int l = k + (1 << j) - 1; l >= k; l--) {
                    subarray.push_back(temp[l]);
                }
            }
            temp = subarray;
        }

        cout << countInversions(temp) << endl;
    }

    return 0;
}