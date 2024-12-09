#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Order {
    string dealer;
    string orderType;
    char commodity;
    int price;
};

void processOrder(Order& currentOrder, map<char, vector<int>>& commodityPrices, map<string, pair<int, int>>& dealerPrices) {
    if (currentOrder.orderType == "SELL") {
        for (auto& commodity : commodityPrices) {
            char currentCommodity = commodity.first;
            if (currentCommodity == currentOrder.commodity) {
                auto it = lower_bound(commodity.second.begin(), commodity.second.end(), currentOrder.price);
                if (it != commodity.second.end() && *it == currentOrder.price) {
                    commodity.second.erase(it); // Successful deal
                    int dealPrice = currentOrder.price;
                    if (!commodity.second.empty()) {
                        dealPrice += commodity.second.back();
                        dealPrice /= 2;
                    }
                    cout << currentOrder.commodity << " " << commodity.second.front() << " " << floor(dealPrice) << " " << commodity.second.back() << endl;
                    break;
                }
            }
        }
    } else {
        for (auto& commodity : commodityPrices) {
            char currentCommodity = commodity.first;
            if (currentCommodity == currentOrder.commodity) {
                auto it = lower_bound(commodity.second.begin(), commodity.second.end(), currentOrder.price);
                if (it != commodity.second.end() && *it == currentOrder.price) {
                    commodity.second.erase(it); // Successful deal
                    int dealPrice = currentOrder.price;
                    if (!commodity.second.empty()) {
                        dealPrice += commodity.second.back();
                        dealPrice /= 2;
                    }
                    cout << currentOrder.commodity << " " << commodity.second.front() << " " << floor(dealPrice) << " " << commodity.second.back() << endl;
                    break;
                }
            }
        }
    }

    if (currentOrder.orderType == "SELL") dealerPrices[currentOrder.dealer].first += currentOrder.price;
    else dealerPrices[currentOrder.dealer].second += currentOrder.price;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        map<char, vector<int>> commodityPrices;
        map<string, pair<int, int>> dealerPrices;

        for (int i = 0; i < n; ++i) {
            Order currentOrder;
            cin >> currentOrder.dealer >> currentOrder.orderType >> currentOrder.commodity >> currentOrder.price;
            if (currentOrder.orderType == "SELL") {
                commodityPrices[currentOrder.commodity].push_back(currentOrder.price);
            } else {
                commodityPrices[currentOrder.commodity].push_back(-currentOrder.price);
            }

            processOrder(currentOrder, commodityPrices, dealerPrices);
        }

        cout << "--" << endl;

        for (auto& dealer : dealerPrices) {
            cout << dealer.first << " " << dealer.second.first << " " << dealer.second.second << endl;
        }

        cout << "----------" << endl;
    }

    return 0;
}