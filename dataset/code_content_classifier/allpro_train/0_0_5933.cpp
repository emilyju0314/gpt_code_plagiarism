#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    long long total_score = 0;
    long long sum = 0;
    long long prefix_sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += scores[i];
        prefix_sum += sum;
        total_score = max(total_score, prefix_sum);
    }
    
    sum = 0;
    long long suffix_sum = 0;
    
    for (int i = n-1; i >= 0; i--) {
        sum += scores[i];
        suffix_sum += sum;
        total_score = max(total_score, suffix_sum);
    }
    
    cout << total_score << endl;
    
    return 0;
}