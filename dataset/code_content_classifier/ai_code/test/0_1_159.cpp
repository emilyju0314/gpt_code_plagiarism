#include <iostream>
#include <vector>

using namespace std;

vector<int> maximum_quadratic_subset(int n) {
    vector<int> subset;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        while (i % 2 == 0) {
            i /= 2;
            cnt++;
        }
        if (cnt > 0) {
            subset.push_back(i);
        }
    }
    return subset;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> subset = maximum_quadratic_subset(n);
    
    cout << subset.size() << endl;
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    
    return 0;
}