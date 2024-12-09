#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Item {
    string name;
    int price;
};

int main() {
    int N_minus, N_plus;

    while (true) {
        cin >> N_minus >> N_plus;

        if (N_minus == 0 && N_plus == 0) {
            break;
        }

        vector<int> negative(N_minus);
        vector<int> positive(N_plus);

        for (int i = 0; i < N_minus; i++) {
            cin >> negative[i];
        }

        for (int i = 0; i < N_plus; i++) {
            cin >> positive[i];
        }

        int M;
        cin >> M;

        vector<Item> items(M);
        map<string, int> itemPrices;

        for (int i = 0; i < M; i++) {
            cin >> items[i].name >> items[i].price;
            itemPrices[items[i].name] = items[i].price;
        }

        int L;
        cin >> L;

        map<pair<int, int>, vector<string>> reactions;

        for (int i = 0; i < L; i++) {
            int I_minus, I_plus, NJ;
            cin >> I_minus >> I_plus >> NJ;

            vector<string> producedItems(NJ);
            for (int j = 0; j < NJ; j++) {
                cin >> producedItems[j];
            }

            reactions[{I_minus, I_plus}] = producedItems;
        }

        int maxPrice = 0;

        for (int i = 0; i <= min(N_minus, N_plus); i++) {
            vector<string> combinedItems;

            for (int j = 0; j < i; j++) {
                for (int k = 0; k < reactions[{j + 1, i - j + 1}].size(); k++) {
                    combinedItems.push_back(reactions[{j + 1, i - j + 1}][k]);
                }
            }

            sort(combinedItems.begin(), combinedItems.end());
            combinedItems.erase(unique(combinedItems.begin(), combinedItems.end()), combinedItems.end());

            int totalPrice = 0;
            for (string item : combinedItems) {
                totalPrice += itemPrices[item];
            }

            maxPrice = max(maxPrice, totalPrice);
        }

        cout << maxPrice << endl;
    }

    return 0;
}