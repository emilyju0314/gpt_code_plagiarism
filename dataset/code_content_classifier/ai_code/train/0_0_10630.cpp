#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> dishes(N);
    
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        dishes[i] = make_pair(A, B);
    }
    
    sort(dishes.begin(), dishes.end(), [](pair<int, int> a, pair<int, int> b){
        return (a.first + a.second) > (b.first + b.second);
    });
    
    long long takahashi = 0, aoki = 0;
    
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            takahashi += dishes[i].first;
        } else {
            aoki += dishes[i].second;
        }
    }
    
    cout << takahashi - aoki << endl;
    
    return 0;
}