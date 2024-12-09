#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int sum = 0, max_time = 0;
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        sum += t[i];
        max_time = max(max_time, t[i]);
        if(sum <= M) {
            result[i] = 0;
        } else {
            int cnt = 0;
            for(int j = 0; j < i; j++) {
                if(t[j] > t[i]) {
                    cnt++;
                }
            }
            result[i] = cnt;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}