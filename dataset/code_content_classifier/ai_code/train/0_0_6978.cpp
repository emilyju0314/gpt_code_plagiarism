#include <iostream>
#include <vector>
using namespace std;

vector<long long> p(vector<long long>& x) {
    int m = x.size();
    vector<long long> y(m + 1);
    for(int i = 0; i < m; i++) {
        y[i + 1] = y[i] + x[i];
    }
    return y;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> A0(n);
    for(int i = 0; i < n; i++) {
        cin >> A0[i];
    }

    int i = 0;
    while(true) {
        vector<long long> Ai = p(A0);
        bool found = false;
        for(int j = 0; j < Ai.size(); j++) {
            if(Ai[j] >= k) {
                found = true;
                break;
            }
        }
        if(found) {
            cout << i << endl;
            break;
        }
        A0 = Ai;
        i++;
    }

    return 0;
}