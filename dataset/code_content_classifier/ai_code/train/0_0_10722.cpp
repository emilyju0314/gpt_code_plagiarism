#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(2*N-1);

    for (int i = 0; i < 2*N-1; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << a[N-1] << endl;

    return 0;
}