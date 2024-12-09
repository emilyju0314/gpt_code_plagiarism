#include <iostream>
#include <vector>
using namespace std;

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int result;
    cin >> result;
    return result;
}

int main() {
    vector<int> a = {4, 8, 15, 16, 23, 42};

    int ab = query(1, 2);
    int ac = query(1, 3);
    int ad = query(1, 4);
    int ae = query(1, 5);

    vector<int> possible_first_two;
    for (int i = 0; i < 6; i++) {
        if (a[i] * a[(i + 1) % 6] == ab) {
            possible_first_two.push_back(a[i]);
            possible_first_two.push_back(a[(i + 1) % 6]);
            break;
        }
    }

    vector<int> possible_first_three;
    for (int i = 0; i < 6; i++) {
        if (a[i] * a[(i + 1) % 6] == ac && a[(i + 2) % 6] == ab / a[i]) {
            possible_first_three.push_back(a[i]);
            possible_first_three.push_back(a[(i + 1) % 6]);
            possible_first_three.push_back(a[(i + 2) % 6]);
            break;
        }
    }

    vector<int> possible_first_four;
    for (int i = 0; i < 6; i++) {
        if (a[i] * a[(i + 1) % 6] == ad && a[(i + 2) % 6] == ac / a[i] && a[(i + 3) % 6] == ab / a[(i + 2) % 6]) {
            possible_first_four.push_back(a[i]);
            possible_first_four.push_back(a[(i + 1) % 6]);
            possible_first_four.push_back(a[(i + 2) % 6]);
            possible_first_four.push_back(a[(i + 3) % 6]);
            break;
        }
    }

    int remaining_sum = ae;
    for (int i = 0; i < 4; i++) {
        remaining_sum -= possible_first_four[i];
    }

    vector<int> final_array = possible_first_four;
    final_array.push_back(remaining_sum);

    cout << "! ";
    for (int num : final_array) {
        cout << num << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}