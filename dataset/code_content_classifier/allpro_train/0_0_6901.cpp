#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }

    long long ans = 0;
    for(int L = 0; L < N-1; L++){
        int max1 = max(P[L], P[L+1]);
        int max2 = min(P[L], P[L+1]);
        ans += max2;
        for(int R = L + 2; R < N; R++){
            if(P[R] < max2){
                max2 = P[R];
                ans += max2;
            }
            else if(P[R] > max2 && P[R] < max1){
                max2 = P[R];
                ans += max2;
            }
            else{
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}