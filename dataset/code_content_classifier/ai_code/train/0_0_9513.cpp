#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<long long> T(N);
    long long total_time = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        total_time += T[i];
    }
    
    cin >> M;
    vector<pair<int, int>> drinks(M);
    
    for (int i = 0; i < M; i++) {
        cin >> drinks[i].first >> drinks[i].second;
    }
    
    sort(drinks.begin(), drinks.end());
    
    long long prefix_sum[N+1] = {0};
    
    for (int i = 0; i < N; i++) {
        prefix_sum[i+1] = prefix_sum[i] + T[i];
    }
    
    for (int i = 0; i < M; i++) {
        int P = drinks[i].first;
        int X = drinks[i].second;
        long long max_score = 0;
        
        for (int j = 0; j < N; j++) {
            if (T[j] <= X) {
                int l = upper_bound(drinks.begin(), drinks.end(), make_pair(j+1,0)) - drinks.begin();
                int r = upper_bound(drinks.begin(), drinks.end(), make_pair(P,0)) - drinks.begin();
                int total_problems = r - l;
                int total_time = prefix_sum[j] - prefix_sum[l-1];
                max_score = max(max_score, total_problems * (total_problems + 1) / 2 - total_time);
            }
        }
        
        cout << max_score << endl;
    }
    
    return 0;
}