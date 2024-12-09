#include <iostream>
#include <vector>

using namespace std;

vector<int> k_bonacci_numbers(int s, int k) {
    vector<int> ans;
    int a = 0, b = 0;
    
    while (a < s) {
        ans.push_back(a);
        int c = a + b;
        a = b;
        b = c;
        if (ans.size() >= k) {
            a = 0;
            for (int i = 1; i <= k; i++) {
                a += ans[ans.size() - i];
            }
        }
    }
    
    return ans;
}

int main() {
    int s, k;
    cin >> s >> k;
    
    vector<int> result = k_bonacci_numbers(s, k);
    
    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}