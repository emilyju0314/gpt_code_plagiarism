#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> column(N);
    for(int i = 0; i < N; i++) {
        cin >> column[i];
    }

    int ans = 0;
    for(int i = 1; i < N; i++) {
        int j = i;
        while(j > 0 && column[j-1] > column[j]) {
            swap(column[j-1], column[j]);
            j--;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}