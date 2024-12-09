#include <iostream>
#include <vector>

using namespace std;

int ask_xor(vector<int>& indices) {
    cout << "? " << indices.size();
    for(int i : indices) {
        cout << " " << i;
    }
    cout << endl;
    int result;
    cin >> result;
    return result;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> temp_indices;
    for(int i = 1; i <= n; i++) {
        if(i != n) temp_indices.push_back(i);
        else {
            int temp_xor = ask_xor(temp_indices);
            if((temp_xor ^ y) < y) {
                // The special icicle is included in temp_indices
                int left = 1, right = n;
                while(left < right) {
                    int mid = (left + right) / 2;
                    vector<int> subset;
                    for(int j = 1; j <= n; j++) {
                        if(j != mid) subset.push_back(j);
                    }
                    if(ask_xor(subset) == temp_xor) right = mid;
                    else left = mid + 1;
                }
                cout << "! " << left << " " << i << endl;
                break;
            } else {
                temp_indices.push_back(n);
            }
        }
    }

    return 0;
}