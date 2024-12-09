#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int max_len = 0;
    int end;
    for(int i=0; i<n; i++){
        if(dp[i]>max_len){
            max_len = dp[i];
            end = i;
        }
    }

    vector<int> result;
    while(end != -1){
        result.insert(result.begin(), end);
        end = prev[end];
    }

    cout << max_len << endl;
    for(int i=1; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}