#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if(n < (k+1)/2){
        cout << -1 << endl;
    }
    else{
        vector<int> ans;
        for(int i = 1; i <= k; i++){
            ans.push_back(i);
        }
        for(int i = k+1; i <= n; i++){
            ans.push_back(i*2);
        }

        for(int num : ans){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}