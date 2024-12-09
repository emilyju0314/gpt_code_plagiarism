#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string initial_state;
    cin >> initial_state;

    vector<vector<int>> subsets(k);
    for(int i = 0; i < k; i++){
        int c;
        cin >> c;
        subsets[i].resize(c);
        for(int j = 0; j < c; j++){
            cin >> subsets[i][j];
        }
    }

    vector<int> operations(n, 0);

    vector<int> prefix_sum(n+1, 0);
    for(int i = 0; i < k; i++){
        bool all_on = true;
        for(auto lamp : subsets[i]){
            if(initial_state[lamp-1] == '0'){
                all_on = false;
                break;
            }
        }
        if(all_on){
            for(auto lamp : subsets[i]){
                prefix_sum[lamp]++;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        prefix_sum[i] += prefix_sum[i-1];
        operations[i-1] = prefix_sum[i];
    }

    for(int i = 0; i < n; i++){
        cout << operations[i] << endl;
    }

    return 0;
}