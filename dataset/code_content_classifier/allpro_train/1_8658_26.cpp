#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>


int main() {
	int m, n; std::cin >> m >> n;
	std::vector<int> plan(n); for (auto& p : plan) std::cin >> p;
	if (m == 2) {
		int odd{ 0 }, even{ 0 };
		for (auto i = 0; i < n; ++i) {
			if ((i + plan[i]) % 2 == 0) {
				++even;
			}
			else {
				++odd;
			}
		}
		std::cout << std::min(odd, even) << std::endl;
	}
	else {
		int prev = -1;
		int count = 0;
		for (const auto p : plan) {
			if (prev == p) {
				++count;
				prev = -1;
			}
			else {
				prev = p;
			}
		}
		std::cout << count << std::endl;
	}
}
