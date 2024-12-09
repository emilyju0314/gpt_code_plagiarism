#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    long long count = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && x[j] - x[i] <= d) {
            j++;
        }
        j--;
        
        long long current_count = j - i;
        count += (current_count * (current_count - 1)) / 2;
    }
    
    cout << count << endl;
    
    return 0;
}