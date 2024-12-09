#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int sum = 0;

    int min_cards = min(A, K);
    sum += min_cards;
    K -= min_cards;

    min_cards = min(B, K);
    K -= min_cards;

    min_cards = min(C, K);
    sum -= min_cards;

    cout << sum << endl;

    return 0;
}