#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> stores;
    
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        stores.push_back({A, B});
    }
    
    sort(stores.begin(), stores.end());
    
    long long total_cost = 0;
    
    for (auto store : stores) {
        int A = store.first;
        int B = store.second;
        
        if (M >= B) {
            total_cost += A * B;
            M -= B;
        } else {
            total_cost += A * M;
            break;
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}