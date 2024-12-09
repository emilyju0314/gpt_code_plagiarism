#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Good {
    int price;
    int discount;
    int required_coupon;
};

int maxGoods(vector<Good>& goods, int budget) {
    vector<int> dp(budget + 1, 0);
    for (Good good : goods) {
        for (int i = budget; i >= good.price; i--) {
            if (i - good.price >= good.discount) {
                dp[i] = max(dp[i], dp[i - good.price] + 1);
            }
        }
    }
    return dp[budget];
}

int main() {
    int n, b;
    cin >> n >> b;

    vector<Good> goods(n);
    for (int i = 0; i < n; i++) {
        cin >> goods[i].price >> goods[i].discount;
        if(i > 0) {
            cin >> goods[i].required_coupon;
        }
    }

    int max_goods = maxGoods(goods, b);
    cout << max_goods << endl;

    return 0;
}