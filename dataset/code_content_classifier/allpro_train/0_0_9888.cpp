#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int countStackExterminableSubarrays(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        stack<int> st;
        for (int j = i; j < n; j++) {
            if (st.empty() || st.top() != arr[j]) {
                st.push(arr[j]);
            } else {
                st.pop();
            }
            if (st.empty()) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int result = countStackExterminableSubarrays(arr);
        cout << result << endl;
    }
    
    return 0;
}