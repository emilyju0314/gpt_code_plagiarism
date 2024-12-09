#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a1(n-1);
    vector<int> a2(n-1);
    vector<int> b(n);

    for(int i = 0; i < n-1; i++) {
        cin >> a1[i];
    }

    for(int i = 0; i < n-1; i++) {
        cin >> a2[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int min_time = 10000000;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int time = 0;

            for(int k = 0; k < n; k++) {
                if(k < i) {
                    time += a1[k];
                } else if(k == i) {
                    time += b[k];
                } else if(k > i && k < j) {
                    time += a2[k-1];
                } else if(k == j) {
                    time += b[k];
                }
            }

            for(int k = n-1; k >= 0; k--) {
                if(k > j) {
                    time += a1[k-1];
                } else if(k == j) {
                    time += b[k];
                } else if(k < j && k > i) {
                    time += a2[k];
                } else if(k == i) {
                    time += b[k];
                }
            }

            min_time = min(min_time, time);
        }
    }

    cout << min_time << endl;

    return 0;
}