#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, W, T;
    cin >> N >> M >> W >> T;

    vector<string> products(M);
    vector<int> weights(M);
    vector<int> prices(M);

    for(int i=0; i<M; i++) {
        cin >> products[i] >> weights[i] >> prices[i];
    }

    vector<vector<pair<string, int>>> towns(N);
    vector<vector<int>> town_coords(N);

    for(int i=0; i<N; i++) {
        int num_products, x, y;
        cin >> num_products >> x >> y;

        town_coords[i] = {x, y};

        for(int j=0; j<num_products; j++) {
            string product_name;
            int price;
            cin >> product_name >> price;

            towns[i].push_back({product_name, price});
        }
    }

    vector<vector<int>> dp(T+1, vector<int>(W+1, 0));

    for(int t=0; t<=T; t++) {
        for(int w=0; w<=W; w++) {
            for(int i=0; i<N; i++) {
                int x = town_coords[i][0];
                int y = town_coords[i][1];

                if(t >= abs(x) + abs(y)) {
                    for(auto& product_sold : towns[i]) {
                        string product_name = product_sold.first;
                        int product_price = product_sold.second;

                        for(int j=0; j<M; j++) {
                            if(products[j] == product_name && weights[j] <= w) {
                                dp[t][w] = max(dp[t][w], dp[t - abs(x) - abs(y)][w - weights[j]] + product_price);
                            }
                        }
                    }
                }
            }
        }
    }

    int max_profit = 0;
    for(int t=0; t<=T; t++) {
        for(int w=0; w<=W; w++) {
            max_profit = max(max_profit, dp[t][w]);
        }
    }

    cout << max_profit << endl;

    return 0;
}