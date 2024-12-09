#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<char> moves;
    int left = 0, right = n - 1;
    vector<int> result;
    
    while (left <= right) {
        if (a[left] < a[right]) {
            if (result.empty() || result.back() < a[left]) {
                result.push_back(a[left++]);
                moves.push_back('L');
            } else if (result.empty() || result.back() < a[right]) {
                result.push_back(a[right--]);
                moves.push_back('R');
            } else {
                break;
            }
        } else {
            if (result.empty() || result.back() < a[right]) {
                result.push_back(a[right--]);
                moves.push_back('R');
            } else if (result.empty() || result.back() < a[left]) {
                result.push_back(a[left++]);
                moves.push_back('L');
            } else {
                break;
            }
        }
    }
    
    cout << result.size() << endl;
    for(char move : moves) {
        cout << move;
    }
    
    return 0;
}