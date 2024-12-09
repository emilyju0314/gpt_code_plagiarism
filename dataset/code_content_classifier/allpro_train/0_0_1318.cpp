#include <iostream>
#include <vector>

using namespace std;

int f(int x, int k) {
    if (x % k != 0) {
        return x;
    } else {
        return f(x / k, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<pair<int, int>> operations;

    while (true) {
        bool found = false;
        int x_idx = -1, y_idx = -1;

        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                int sum = numbers[i] + numbers[j];
                int new_num = f(sum, k);
                if (new_num == 1) {
                    cout << "YES" << endl;
                    while (!operations.empty()) {
                        pair<int, int> op = operations.back();
                        cout << op.first << " " << op.second << endl;
                        operations.pop_back();
                    }
                    cout << numbers[i] << " " << numbers[j] << endl;
                    return 0;
                }

                if (new_num < sum) {
                    found = true;
                    x_idx = i;
                    y_idx = j;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            break;
        }

        operations.push_back({numbers[x_idx], numbers[y_idx]});
        int new_num = numbers[x_idx] + numbers[y_idx];
        numbers.erase(numbers.begin() + x_idx);
        if (y_idx < x_idx) y_idx--;
        numbers.erase(numbers.begin() + y_idx);
        numbers.push_back(f(new_num, k));
    }

    cout << "NO" << endl;

    return 0;
}