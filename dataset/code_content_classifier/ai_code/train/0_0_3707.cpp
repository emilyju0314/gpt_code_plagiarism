#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int max_value = 0;
    vector<int> operations;
    while (a.size() > 1) {
        int max_ind = 0;
        for (int i = 1; i < a.size() - 1; i++) {
            if (a[i] + a[i - 1] > a[max_ind] + a[max_ind + 1]) {
                max_ind = i - 1;
            }
        }
        
        max_value += a[max_ind] + a[max_ind + 1];
        operations.push_back(max_ind + 1);
        
        a.erase(a.begin() + max_ind);
        a.erase(a.begin() + max_ind);
    }

    cout << max_value << endl;
    cout << operations.size() << endl;
    for (int op : operations) {
        cout << op << endl;
    }

    return 0;
}